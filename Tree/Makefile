# Use emcc to compile the Tree Class, generate WebAssembly byte code,
# JavaScript glue code, and an html file (tree.html) as output.
# --bind is used to bind C++ functions and classes to JavaScript
# [-Ox] represents build optimisations (this also minifies the code)
# -s WASM=1 specifies that we want WASM output (default output: asm.js)
# --shell-file specifies our HTML template shell file
make:
	emcc --bind -o tree.html tree.cpp -O3 -s WASM=1 --shell-file templates/mytree.html

# Call 'make run' to make runscript.sh executable, then run the .sh file
run:
	chmod +x runscript.sh
	./runscript.sh
