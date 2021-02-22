#!/bin/bash
# After compiling with make, move generated files to appropriate locations
mv tree.html templates/tree.html
mv tree.js static/tree.js
mv tree.wasm static/tree.wasm

# Use the stream editor to edit location of javascript source
sed -i -e "s/src=tree.js/src=static\/tree.js/" templates/tree.html
