<script lang="ts">
    import { onMount } from 'svelte';
    import Module from '$lib/compiler/1905066_parser'
    import CodeMirror from "svelte-codemirror-editor";
    import { cpp } from "@codemirror/lang-cpp";
    import { Button } from "$lib/components/ui/button"
    import * as Tabs from "$lib/components/ui/tabs";
    import { Copy } from 'radix-icons-svelte';

    let code = `#include<stdio.h>
#include<stdlib.h>
// include statesments are ignored.
// actually lines starting with # are ignored.

void fun(int x){
    int i;
    for(i=0; i<x; i++){
        println(i);
    }
}

int main()
{
    int a, b, c;
    println("Enter two numbers- ");
    scan(a);
    scan(b);

    c = a + b;
    print("Sum of a and b = ");
    println(c);

    fun(5);

    return 0;
}
`;

    let asm = '';
    let optimized_asm = '';
    let error = '';
    let log = '';
    let parseTree = '';
    let output_tab = 'asm';



    let mod:any;
    

    function clear_outputs(){
        asm = '';
        optimized_asm = '';
        error = '';
        log = '';
        parseTree = '';
    }
    

    async function compile(){

        clear_outputs();
        

        mod = await Module();
        mod.FS.mkdir('/files');
        mod.FS.writeFile('./files/input.c', code);


        var result = mod.ccall('main', 'number', null, null)
        asm = mod.FS.readFile('./files/code.asm', { encoding: 'utf8' });
        optimized_asm = mod.FS.readFile('./files/optimized_code.asm', { encoding: 'utf8' });
        error = mod.FS.readFile('./files/error.txt', { encoding: 'utf8' });
        log = mod.FS.readFile('./files/log.txt', { encoding: 'utf8' });
        parseTree = mod.FS.readFile('./files/parseTree.txt', { encoding: 'utf8' });

        if(error){
            output_tab = 'error';
        }
        



    }



</script>


<div class="flex flex-col lg:flex-row flex-grow lg:overflow-hidden w-full">
    
    <div class="w-full lg:w-1/2  overflow-auto  border-r pr-5">
       
        <Tabs.Root value="code" class="w-full">
            <Tabs.List class="w-full justify-between bg-inherit">
              <Tabs.Trigger value="code">input.c</Tabs.Trigger>

            <div class="">
                <Button class="text-xs" size="sm" on:click={compile}>Compile</Button>
            </div>
             
            </Tabs.List>
            
            <Tabs.Content value="code">
                <CodeMirror class="w-full h-full text-lg overflow-auto"
                    bind:value={code} lang={cpp()}
                    tabSize={4}
                    lineWrapping={true}
                    styles={{
                        ".cm-gutters": {
                            backgroundColor: "inherit",
                        }
                    }}
                />
            </Tabs.Content>






        </Tabs.Root>
    </div>

   
    <div class="w-full lg:w-1/2 overflow-auto">
        <Tabs.Root bind:value={output_tab} class="w-full">
            <Tabs.List class="w-full justify-between">
                <div class="w-full justify-start gap-x-5">
                    <Tabs.Trigger value="asm">Assembly</Tabs.Trigger>
                    <Tabs.Trigger value="optimized_asm">Optimized-Assembly</Tabs.Trigger>
                    <Tabs.Trigger value="error">Error</Tabs.Trigger>
                    <Tabs.Trigger value="parseTree">Parse Tree</Tabs.Trigger>
                </div>                
            </Tabs.List>
            
            <Tabs.Content value="asm">
                <CodeMirror class="w-full h-full text-xl overflow-auto"
                    bind:value={asm}
                    tabSize={4}
                    readonly={true}
                    styles={{
                        ".cm-gutters": {
                            backgroundColor: "inherit",
                        }
                    }}
                />
            </Tabs.Content>

            <Tabs.Content value="optimized_asm">
                <CodeMirror class="w-full h-full text-xl overflow-auto"
                    bind:value={optimized_asm}
                    tabSize={4}
                    readonly={true}
                    styles={{
                        ".cm-gutters": {
                            backgroundColor: "inherit",
                        }
                    }}
                />
            </Tabs.Content>

            <Tabs.Content value="error">
                <CodeMirror class="w-full h-full text-xl overflow-auto"
                    bind:value={error}
                    tabSize={4}
                    readonly={true}
                    styles={{
                        ".cm-gutters": {
                            backgroundColor: "inherit",
                        }
                    }}
                />
            </Tabs.Content>


            <Tabs.Content value="parseTree">
                <CodeMirror class="w-full h-full text-xl overflow-auto"
                    bind:value={parseTree}
                    tabSize={4}
                    lineWrapping={true}
                    readonly={true}
                    styles={{
                        ".cm-gutters": {
                            backgroundColor: "inherit",
                        }
                    }}
                />
            </Tabs.Content>
            




        </Tabs.Root>

    </div>

</div>
