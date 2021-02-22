# Copyright (c) 2021, Shelley Wong
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.
#
# file: Tree/tree.py
#
# Flask application for binary tree visualization

from flask import Flask, render_template, request, redirect
from flask import make_response, url_for
from forms import TreeCmds
import sys

app = Flask(__name__, instance_relative_config=True)
app.config.from_object('config.BaseConfig')
app.config.from_pyfile('config.py')

@app.route('/')
def index():
    return 'Index for Binary Tree examples'

# GET launch page: a form to gather user input for linked list visualization
# POST: send data from the form to be used for the linked list visualization
@app.route('/tree', methods=['GET', 'POST'])
def tree():
    form = TreeCmds(request.form)
    submit = False
    if request.method == 'GET':
        name1 = request.form.get('name1')
        array1 = request.form.get('array1')
        name2 = request.form.get('name2')
        array2 = request.form.get('array2')
        name3 = request.form.get('name3')
        array3 = request.form.get('array3')
        print('Launching Binary Tree Visualization')
        context = dict(form=form, submit=submit)
        resp = make_response(render_template('launch.html', **context))
        return resp
    elif request.method == 'POST':
        name1 = request.form['name1']
        array1 = request.form['array1']
        name2 = request.form['name2']
        array2 = request.form['array2']
        name3 = request.form['name3']
        array3 = request.form['array3']
        submit = True
        context = dict(form=form, submit=submit)
        resp = make_response(render_template('tree.html', **context))
        return resp
    else:
        context = dict(form=form, submit=submit)
        resp = make_response(render_template('launch.html', **context))
        # May need to set a same-site cookie for first-party contexts
        #resp.set_cookie('cookie1', 'value1', samesite='Lax')
        # Ensure you use "add" to not overwrite existing cookie headers
        # Set a cross-site cookie for third-party contexts
        #resp.headers.add('Set-Cookie','cookie2=value2; SameSite=None; Secure')
        return resp
