;;;; This script binds system functions to call able aliases


;; This is the call table for runtime executable functions
;; All callable functions should go here.
;; string name for key, function for value
(defparameter *call-table* (make-hash-table))
