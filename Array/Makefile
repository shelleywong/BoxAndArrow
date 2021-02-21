# Use emcc to compile array.cpp -- generate WebAssembly byte code,
# JavaScript glue code, and an html file (function.html) as output.
# [-Ox] represents build optimisations; also minifies code
# -s WASM=1 specifies that we want WASM output (default output: asm.js)
# --shell-file templates/myarray.html specifies an html template file 
# to utilize (this file is implemented prior to compilation)
# NO_EXIT_RUNTIME=1 is included; otherwise, when main() exits, the 
# runtime would be shut down.
# We then export all functions in array.cpp, plus Emscripten methods

sfile = templates/myarray.html
functions = ['_find_largest', '_calc_sum', '_double_vals', '_rotate_left', \
'_is_sorted', '_print', '_malloc', '_free']

make:
	emcc -o array.html array.cpp -O3 -s WASM=1 --shell-file $(sfile) -s NO_EXIT_RUNTIME=1 -s "EXPORTED_FUNCTIONS=$(functions)" -s "EXTRA_EXPORTED_RUNTIME_METHODS=['cwrap']"

# Call 'make run' to make runscript.sh executable, then run the .sh file
run:
	chmod +x runscript.sh
	./runscript.sh
