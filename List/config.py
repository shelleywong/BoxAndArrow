# Copyright (c) 2021, Shelley Wong
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.
#
# file: List/config.py
#
# Base configuration set to development configuration (with testing and 
# debugging). Production configuration set for production. To use the 
# Flask form, you will need a SECRET_KEY. Include this in a private 
# directory (ignore the file for git): instance/config.py

class BaseConfig:
    TESTING = True
    DEBUG = True
    FLASK_ENV = 'development'
    STATIC_FOLDER = 'static'
    TEMPLATES_FOLDER = 'templates'

class ProdConfig(BaseConfig):
    FLASK_ENV = 'production'
    DEBUG = False
    TESTING = False
