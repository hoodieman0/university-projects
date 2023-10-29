\ radius function ( diameter >> radius )
: radius
        2 /     ( diameter / 2 | diameter >> radius )
;

\ circumference function ( diameter >> circumference )
: circumference
    22 * 7 /    ( [diameter * 22] / 7 | diameter >> circumference )
;

\ area function ( diameter diameter >> area )
: area
    22 * * 28 /     ( [22 * diameter * diameter] / 28 | d1 d1 >> area )
;

\ circle function ( diameter >> )
: circle 
    dup 0= if
        ." Error: Cannot have a diameter of zero! " CR
        bye
    then

    dup 0 > if                  ( duplicate the diameter, see if diameter is positive | d1 >> d1 d1 0 > )
        dup dup area            ( diameter diameter diameter >> diameter area )
        swap                    ( diameter area >> area diameter)
        
        dup circumference       ( area diameter diameter >> area diameter circumference )
        swap                    ( area diameter circumference >> area circumference diameter)
        
        dup radius              ( area circumference diameter diameter >> area circumference diameter radius )
        swap                    ( area circumference diameter radius >> area circumference radius diameter)

        ." Diameter = " . CR
        ." Radius = " . CR
        ." Circumference = " . CR
        ." Area = " . CR 
        
    else
        ." You cannot have a negative number for a diameter! Input = " . CR
    then
;

5 circle CR
200 circle CR
10 circle CR
11 circle CR

-3 circle CR
0 circle CR

12 circle CR        \ This should never run
