#!/bin/bash
# After compiling with make, move generated files to the locations 
# expected by the Flask app
mv array.html templates/array.html
mv array.js static/array.js
mv array.wasm static/array.wasm

# Use the stream editor to edit location of javascript source
sed -i -e "s/src=array.js/src=static\/array.js/" templates/array.html
