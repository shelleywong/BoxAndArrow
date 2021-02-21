# Copyright (c) 2021, Shelley Wong
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.
#
# file: Array/forms.py
#
# Include a form for gathering user input for the visualization. 
# User can choose the functions to test and the values that will be
# tested with each command.

from flask_wtf import FlaskForm
from wtforms import StringField, SelectField
from wtforms.validators import InputRequired

FUNCTION_NAMES = [('largest', 'largest'), ('sum', 'sum'), 
    ('double', 'double'), ('rotate_left', 'rotate_left'),
    ('is_sorted', 'is_sorted')]

class ArrCmds(FlaskForm):
    name1 = SelectField(
        'Function 1 Command', 
        choices=FUNCTION_NAMES, 
        validators=[InputRequired()],
    )
    array1 = StringField(
        'Array 1 Values', 
        default='0',
        validators=[InputRequired()]
    )
    name2 = SelectField(
        'Function 2 Command', 
        choices=FUNCTION_NAMES, 
        validators=[InputRequired()]
    )
    array2 = StringField(
        'Array 2 Values', 
        default='0',
        validators=[InputRequired()]
    )
    name3 = SelectField(
        'Function 3 Command', 
        choices=FUNCTION_NAMES, 
        validators=[InputRequired()]
    )
    array3 = StringField(
        'Array 3 Values', 
        default='0',
        validators=[InputRequired()]
    )
 
