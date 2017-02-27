#include "imagepreproc.h"

ImagePreProc::ImagePreProc(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	// make connection
	makeConnection();

}

ImagePreProc::~ImagePreProc()
{

}

void ImagePreProc::makeConnection()
{
	connect(ui.bt_browseSrc, SIGNAL(clicked()), this, SLOT(browseSrc()));
	connect(ui.bt_browseFinal, SIGNAL(clicked()), this, SLOT(browseFinal()));
	connect(ui.bt_browseTrain, SIGNAL(clicked()), this, SLOT(browseTrain()));
	connect(ui.bt_start, SIGNAL(clicked()), this, SLOT(startProcess()));
	connect(ui.bt_trainInfo, SIGNAL(clicked()), this, SLOT(setTrainInfo()));
	connect(ui.bt_trainSummary, SIGNAL(clicked()), this, SLOT(createTrainTxt()));
}

void ImagePreProc::getSourceImageFiles(QFileInfoList &fileList)
{
	fileList.clear();
	QDir fdr(ui.ed_src->text());
	// set filter
	QStringList filters;
	filters << "*.jpg" << "*.png";
	fdr.setNameFilters(filters);
	fileList = fdr.entryInfoList();
}

void ImagePreProc::browseSrc()
{
	QString fdrName = QFileDialog::getExistingDirectory(this, "Select Source Directory","C:/Users/Josh Lo/Documents/Bulk Image Downloader");
	ui.ed_src->setText(fdrName);
	QString fout = QString("%1/resized").arg(fdrName);
	ui.ed_final->setText(fout);
	fout = QString("%1/train").arg(fdrName);
	ui.ed_train->setText(fout);
}
void ImagePreProc::browseFinal()
{
	QString fdrName = QFileDialog::getExistingDirectory(this, "Select Final Directory", "C:/Users/Josh Lo/Documents/Bulk Image Downloader");
	ui.ed_final->setText(fdrName);
}
void ImagePreProc::browseTrain()
{
	QString fdrName = QFileDialog::getExistingDirectory(this, "Select Final Directory", "C:/Users/Josh Lo/Documents/Bulk Image Downloader");
	ui.ed_train->setText(fdrName);
}

void ImagePreProc::startProcess()
{
	// setup variable
	cv::Mat src, dst;
	QFileInfoList fileList;

	// get files 
	getSourceImageFiles(fileList);

	int srcHt, srcWd, finalHt, finalWd;
	finalHt = 270;
	finalWd = 480;

	for (auto fi : fileList)
	{
		// message
		std::cout << "Processing: " << fi.fileName().toStdString() << std::endl;
		// read image
		src = cv::imread(fi.absoluteFilePath().toStdString());
		
		// error handling
		if(src.cols==0 || src.rows==0)
		{
			continue;
		}

		// pyramid down- or up-sampling
		srcHt = src.rows;
		srcWd = src.cols;

		cv::resize(src, dst, cv::Size(finalWd, finalHt));
		
		// make a folder to save image
		QDir fdr(ui.ed_final->text());
		if (!fdr.exists())
		{
			fdr.mkpath(".");
		}

		// save image now
		QString fout = QString("%1/%2").arg(ui.ed_final->text()).arg(fi.fileName());
		cv::imwrite(fout.toStdString(), dst);
	}

}
void ImagePreProc::setTrainInfo()
{
	// setup variable
	cv::Mat src;
	QFileInfoList fileList;
	QDir fdr(ui.ed_final->text());	
	QDir fdrTrain(ui.ed_train->text());

	// get files 
	QStringList filters;
	filters << "*.jpg" << "*.png";
	fdr.setNameFilters(filters);
	fileList = fdr.entryInfoList();

	// setup window
	std::string winN = "Set Training Info";
	cv::namedWindow(winN, cv::WINDOW_FULLSCREEN);
	

	for (auto fi : fileList)
	{
		// read image
		src = cv::imread(fi.absoluteFilePath().toStdString());
		
		// error handling
		if (src.cols == 0 | src.rows == 0)
		{
			continue;
		}
		
		// set feedback function
		MouseData mdata(winN, &src);
		cv::setMouseCallback(winN, mouseCallback, (void*)&mdata);

		// show image
		cv::imshow(winN, src);

		char c = cv::waitKey();
		if (c == 27) // escape key
		{
			cv::setMouseCallback(winN, NULL, NULL);
			cv::destroyWindow(winN);
			break;
		}
		else if (c == 127)  // delete key
		{
			// delete the current image file
			QFile fimg(fi.absoluteFilePath());
			fimg.remove();
			continue;
		}

		// report
		std::ofstream fid;
		QString fname = QString("%1/%2.txt").arg(fdrTrain.absolutePath()).arg(fi.completeBaseName());
		QString fimgname= QString("%1/%2").arg(fdrTrain.absolutePath()).arg(fi.fileName());
		std::cout << "save to: "<< fname.toStdString()<< std::endl;
		
		if (!mdata.objs.empty())
		{
			if (!fdrTrain.exists())
			{
				fdrTrain.mkpath(".");
			}
			// write the text file
			fid.open(fname.toStdString(),std::ios_base::app);
			for (auto obj : mdata.objs)
			{
				fid << ui.ed_classID->text().toStdString() << " " << obj.x << " " << obj.y << " " << obj.w << " " << obj.h << "\n";
			}
			fid.close();
			// move the image file
			QFile fimg(fi.absoluteFilePath());
			fimg.copy(fimgname);			
		}
	}
	cv::setMouseCallback(winN, NULL, NULL);
	cv::destroyWindow(winN);	

}
void ImagePreProc::createTrainTxt()
{
	// get all image file
	QDir fdr(ui.ed_train->text());
	QFileInfoList fileList;
	QStringList filters;
	filters << "*.jpg" << "*.png";
	fdr.setNameFilters(filters);
	fileList = fdr.entryInfoList();

	// output file
	QString fname = QString("%1/train.txt").arg(fdr.absolutePath());
	std::ofstream fid;

	std::string fdrStr = ui.ed_trainFdr->text().toStdString();

	if (fileList.count() > 0)
	{
		fid.open(fname.toStdString());
		for (auto fi : fileList)
		{
			fid << fdrStr << "/" << fi.fileName().toStdString()<< std::endl;
		}
		fid.close();
		std::cout << "train.txt has been created successfully! \n";
	}
	else
	{
		std::cout << "No image files in the specified folder! \n";
	}


}

void mouseCallback(int ev, int x, int y, int flags, void * userdata)
{
	// convert back 
	MouseData *mdata= (MouseData*)userdata;
	
	if (ev == cv::EVENT_LBUTTONDOWN)
	{
		mdata->xp1 = x;
		mdata->yp1 = y;
		mdata->xp2 = x;
		mdata->yp2 = y;
		mdata->clicked = true;
	}
	else if (ev == cv::EVENT_LBUTTONUP)
	{		
		// report data
		ObjectData obj;
		double x1, x2, y1, y2;
		obj.xp1 = mdata->xp1;
		obj.xp2 = mdata->xp2;
		obj.yp1 = mdata->yp1;
		obj.yp2 = mdata->yp2;

		x1 = double(mdata->xp1);
		y1 = double(mdata->yp1);
		x2 = double(mdata->xp2);
		y2 = double(mdata->yp2);
		obj.w = std::abs(x2 - x1) / double(mdata->cols);
		obj.h = std::abs(y2 - y1) / double(mdata->rows);
		obj.x = 0.5*double(x1 + x2) / double(mdata->cols);
		obj.y = 0.5*double(y1 + y2) / double(mdata->rows);
		obj.classNo = 0;
		
		mdata->objs.push_back(obj);
		mdata->printObjects();

		// reset
		mdata->xp1 = 0;
		mdata->yp1 = 0;
		mdata->xp2 = 0;
		mdata->yp2 = 0;
		mdata->clicked = false;
	}
	else if (ev == cv::EVENT_MOUSEMOVE)
	{
		if (mdata->clicked)
		{
			mdata->xp2 = x;
			mdata->yp2 = y;
		}
	}
	else if (ev == cv::EVENT_RBUTTONDOWN)
	{
		if (!mdata->objs.empty())
		{
			mdata->objs.pop_back();
		}
		mdata->printObjects();
	}

	// update image
	cv::Mat img1;
	mdata->img->copyTo(img1);
	cv::rectangle(img1, cv::Point(mdata->xp1, mdata->yp1),
		cv::Point(mdata->xp2, mdata->yp2), cv::Scalar(0, 0, 255));
	for (auto ob : mdata->objs)
	{
		cv::rectangle(img1, cv::Point(ob.xp1, ob.yp1),
			cv::Point(ob.xp2, ob.yp2), cv::Scalar(255, 0, 0));
	}
	cv::imshow(mdata->winName, img1);	
}

void MouseData::printObjects()
{
	int ct = 0;
	for (auto ob : objs)
	{
		std::cout << "obj "<<ct<<": "<< ob.x << " " << ob.y << " " << ob.w << " " << ob.h << "\n";
		ct++;
	}
}
