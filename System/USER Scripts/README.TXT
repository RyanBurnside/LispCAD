This is the directory for the user defined routines.
Part of the appeal of LispCAD is being able to simply program the features
and drawing routines which you need.

For example, if you are a machinist and you draw a lot of bolts you may
write a LispCAD routine to draw a bolt after asking the user for various
parameters. This might save you a handful of minutes next time. Thanks to the
nature of Lisp your routine is just as valid as the system defined routines.
Later, you might wish to make a new procedure that defines groups of bolts
radially positioned so you can easily make bolted gaskets etc.

Write a procedure once and never have to draw a shape manually again.
In fact, you can have entire libraries of premade object drawing procedure.

You can have layer upon layer of procedures making very complex shapes.
The whole key comes from building higher level procedures from small flexible
ones. This mirrors how Lisp builds complex procedures from small flexible
procedures.

Lastly,
Ensure you register your procedure in the LispCAD system so you may call it!
Be sure to name your new routine with a .lisp file type.
If you are in windows you will need to "enable file extensions" to see the suffix.

Happy Hacking and Drafting!
-Ryan Burnside
