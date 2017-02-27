#ifndef IMAGEPREPROC_H
#define IMAGEPREPROC_H

#include <QtWidgets/QWidget>
#include "GeneratedFiles\ui_imagepreproc.h"
#include <opencv2\opencv.hpp>
#include <iostream>
#include <qfiledialog.h>
#include <vector>
#include <string>
#include <fstream>

class ImagePreProc : public QWidget
{
	Q_OBJECT

public:
	ImagePreProc(QWidget *parent = 0);
	~ImagePreProc();
	
	void makeConnection();
	void getSourceImageFiles(QFileInfoList &fileList);
	
private slots:
	void browseSrc();
	void browseFinal();
	void browseTrain();
	void startProcess();
	void setTrainInfo();
	void createTrainTxt();


private:
	Ui::ImagePreProcClass ui;
};


struct ObjectData
{
	ObjectData() :
		x(0), y(0), w(0), h(0), classNo(0),
		xp1(0),yp1(0),xp2(0),yp2(0){}
	int classNo;
	int xp1, yp1, xp2, yp2;
	double x, y, w, h;  // [0,1]
};

struct MouseData
{
	MouseData(const std::string &winName, cv::Mat *src) :
		cols(src->cols), rows(src->rows), img(src),
		xp1(0), yp1(0), xp2(0), yp2(0), winName(winName), clicked(false)
	{
		objs.clear();
	}

	void printObjects();


	bool clicked;
	const std::string winName;
	const cv::Mat *img;
	int cols;
	int rows;
	int xp1, yp1;     // in pixels
	int xp2, yp2;     // in pixels
	std::vector<ObjectData> objs; 
};
void mouseCallback(int ev, int x, int y, int flags, void *userdata);

#endif // IMAGEPREPROC_H
