
! Beam Homogenizer by Nam Kim 10/02/2006
! Updated for OpticStudio 15 by Alissa Wersal 8/3/2015
! This macro creates Merit Function that generates ray targets neccesary to 
! optimize Gaussian to Top hap beam homogenizer

CLOSEWINDOW	       # run macro in quite mode (no text output window)
DELETEMFO ALL          # delete the current MF

W = 5			 # gaussian INPUT beam waist
K = 25			 # output beam radius
sample = 80	 # pupil sampling

SYSP 11, W*6     # make the EP Diameter 6 times (EP Radius 3 times) the waist, to 
		 # sample well beyod the beam waist

SYSP 12, 1       # set Gaussian apodization in the system property. Unneccesary for optimization
		 # but needed for analysis using geometrical rays

apod_factor = 1/POWR((1/3),2)   # 1/3 is the ratio of waist to EP Radius
SYSP 13, apod_factor	 # set the system apodization factor so that the 1/e^2 intensity 
			 # point is at the waist W. The Entrance Pupil Raidus is still 3*W


FOR I, 1, sample+1, 1
	INSERTMFO I			 # insert operand
	SETOPERAND I, 11, "REAY"	 # set operand type to REAY
	SETOPERAND I, 9, 1		 # set the weight to 1

	norm_pupil_coord = I/sample
	
	X = norm_pupil_coord*W*3	 # Un-normalized pupil coordinate 
	

	S = K*SQRT(1-EXPE(-2*POWR(X,2)/POWR(W,2))) # same as the final equation in the article

	SETOPERAND I, 8, -S		 # set target. Positive input coordinate has negative 
					 # output coordinate (positive lens) thus the negative sign
	SETOPERAND I, 7, norm_pupil_coord  # Set Py column of the operand 
	SETOPERAND I, 2, NSUR()    # specify the image surface for the REAY value calculation

NEXT

OPTIMIZE 
UPDATE ALL	 # Update all windows
END
	