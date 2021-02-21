#!/bin/bash
# After compiling with make, move generated files to appropriate locations
mv list.html templates/list.html
mv list.js static/list.js
mv list.wasm static/list.wasm

# Use the stream editor to edit location of javascript source
sed -i -e "s/src=list.js/src=static\/list.js/" templates/list.html
