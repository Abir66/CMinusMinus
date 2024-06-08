<script lang="ts">
	import Navbar from './navbar.svelte';
	import { page } from '$app/stores';
	import { Toaster } from "$lib/components/ui/sonner";

	// paths that don't need navbar
	const full_width_paths_starts_with = ['/compiler'];

	$: pathname = $page.url.pathname;

    console.log($page.url.pathname);


</script>


<Toaster />
{#if pathname.startsWith('/compiler')}
    <div class="flex flex-col h-screen w-full">
        <Navbar/>
        <slot />
    </div>
{:else}
    <Navbar/>
    <div class="container mx-auto px-[5%] py-4">
        <slot />
    </div>
{/if}



