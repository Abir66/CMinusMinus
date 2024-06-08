# C--

An in-browser compiler made with `flex` and `bison` that translates a subset of **C code** into assembly language for the **Intel 8086 processor**.

This was done as series of four assignments for the course [***CSE310 - Compiler Sessional***](https://github.com/Abir66/CSE-310-Compiler-Sessional/tree/main) at BUET.


## Building

First compile the compiler

```bash
# go to the wasm directory
cd wasm

# compile the compiler
./run.sh
```

This will build the parser and move the `wasm` and `js` to `/src/lib/compiler` directory



Next, for sveltekit, start a development server:
    
```bash
npm run dev

# or start the server and open the app in a new browser tab
npm run dev -- --open
```

To create a production version of your app:

```bash
npm run build
```

You can preview the production build with `npm run preview`.

