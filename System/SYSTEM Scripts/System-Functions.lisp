;;;; This script binds system functions to call able aliases

(print "Entering system defined functions file...")

(defun add-rectangle (x y x2 y2)
  (add-line x y x2 y)
  (add-line x y x y2)
  (add-line x y2 x2 y2)
  (add-line x2 y x2 y2))

(defun add-triangle (x y x2 y2 x3 y3)
  (add-line x y x2 y2)
  (add-line x2 y2 x3 y3)
  (add-line x3 y3 x y))

(defun add-ngon (cen-x cen-y radius num-sides)
  (let ((sub-step (/ (* 2.0 pi) num-sides)))
    (dotimes (i num-sides)
      (let* ((angle (* i sub-step))
	     (x (+ cen-x (* (cos angle) radius)))
	     (y (+ cen-y (* (sin angle) radius)))
	     (x2 (+ cen-x (* (cos (+ angle sub-step)) radius)))
	     (y2 (+ cen-y (* (sin (+ angle sub-step)) radius))))
	(add-line x y x2 y2)))))

(print "Finished loading system defined functions")
