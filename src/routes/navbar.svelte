<script lang="ts">
	import '../app.pcss';
	import { Button } from '$lib/components/ui/button';
	import { HamburgerMenu } from 'radix-icons-svelte';
	import { GithubLogo } from 'radix-icons-svelte';

	import clogo from '$lib/assets/c--logo.svg'
	
	let showMenu = false;
	
	function toggleNavbar() {
		showMenu = !showMenu;
	}
</script>




<div>
	<div class="border-b-2 border-zinc-300 dark:border-zinc-800">
		<nav class="container mx-auto px-[5%] py-4 md:flex md:items-center md:justify-between">
			<div class="flex items-center justify-between">
				<!-- <img src={clogo} alt="C"/> -->
				<a class="text-xl flex  whitespace-nowrap font-semibold md:text-2xl" href="/">C--</a>
				<!-- Mobile menu button -->
				<Button variant="ghost" on:click={toggleNavbar} class="flex md:hidden"><HamburgerMenu/></Button>
			</div>

			<!-- Mobile Menu open: "block", Menu closed: "hidden" -->
			<div class="mt-8 w-full flex-col justify-between space-y-4 md:mt-0 md:flex md:flex-row md:items-center md:space-x-10 md:space-y-0
		  {showMenu ? 'flex' : 'hidden'}"
			>
				<div class="flex text-sm flex-col space-y-5 md:ml-10 md:flex-row md:space-x-5  md:space-y-0 }">
					<a href={`/compiler`}>Compiler</a>
					<!-- <a href="/problems">Problems</a>
					<a href="/blogs">Blogs</a> -->
				</div>

				<div class="flex flex-col md:flex-row space-y-5 md:space-x-5 md:space-y-0">
					
				</div>
			</div>
		</nav>
	</div>
</div>




