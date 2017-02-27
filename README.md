# ImagePreProc
Image pre-processing tool for preparing photos before object detection model training 

- source directory is the folder with all the photos to be processed
- photos in the source directory will be resized to a new size and placed in the **resized** folder
- objects in photos in the **resized** directory will be manually picked and a text file will be generated
	+ For example for img1.jpg, img1.txt will be created containing:
		1 0.716797 0.395833 0.216406 0.147222
		0 0.687109 0.379167 0.255469 0.158333
		1 0.420312 0.395833 0.140625 0.166667
		<object-class> <x> <y> <width> <height> all in normalized units [0,1]
- a train.txt file will be automatically created in the **resized** directory:
	data/obj/img1.jpg
	data/obj/img2.jpg
	data/obj/img3.jpg

This image + text file package can be used for training YOLO net model.


