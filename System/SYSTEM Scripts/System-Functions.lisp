;;;; This script binds system functions to call able aliases
;;;; These functions build upon C++11 function primatives like add-line

(print "Entering system defined functions file...")

(defun deg-to-rad (degrees)
  "Converts given degrees to radians (lossy)"
  (* degrees 0.0174533))

(defun rad-to-deg (radians)
  "Conversion given radians to degrees (lossy)"
  (* radians 57.2958))

(defun add-rectangle (x y x2 y2)
  "Adds 4 lines in a rectangle using upper left and lower right corners"
  (add-line x y x2 y)
  (add-line x y x y2)
  (add-line x y2 x2 y2)
  (add-line x2 y x2 y2))

(defun add-square (x y size)
  "Add 4 lines in a square given upper left position and side size"
  (add-rectangle x y (+ x size) (+ y size)))

(defun add-triangle (x y x2 y2 x3 y3)
  "Adds 3 lines in a triangle"
  (add-line x y x2 y2)
  (add-line x2 y2 x3 y3)
  (add-line x3 y3 x y))

(defun add-ngon (cen-x cen-y radius num-sides)
  "Adds a polygon inscribed in radius with num-sides number of sides"
  (let ((sub-step (/ (* 2.0 pi) num-sides)))
    (dotimes (i num-sides)
      (let* ((angle (* i sub-step))
	     (x (+ cen-x (* (cos angle) radius)))
	     (y (+ cen-y (* (sin angle) radius)))
	     (x2 (+ cen-x (* (cos (+ angle sub-step)) radius)))
	     (y2 (+ cen-y (* (sin (+ angle sub-step)) radius))))
	(add-line x y x2 y2)))))

;;; Just for fun functions
(defun add-golden-rectangle (x y width)
  "Creates a golden ratio rectangle given a position and width"
  (add-rectangle x y (+ x width) (+ y (* width .618033))))

(print "Finished loading system defined functions")
