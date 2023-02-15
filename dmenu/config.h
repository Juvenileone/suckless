/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 0; /* -b  option; if 0, dmenu appears at bottom     */
static int fuzzy = 1;  /* -F  option; if 0, dmenu doesn't use fuzzy matching     */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"JetBrains Mono:size=15:antialias=true:autohint=true"};
static const char *prompt = NULL;	 /* -p  option; prompt to the left of input field */
static char termcol0[] = "#282a36";	 /* Background   */
static char termcol1[] = "#44475a";	 /* Current Line     */
static char termcol2[] = "#44475a";	 /* Selection   */
static char termcol3[] = "#f8f8f2";	 /* Foreground  */
static char termcol4[] = "#6272a4";	 /* Comment    */
static char termcol5[] = "#8be9fd";	 /* Cyan    */
static char termcol6[] = "#50fa7b";	 /* Green    */
static char termcol7[] = "#ffb86c";	 /* Orange    */
static char termcol8[] = "#ff79c6";	 /* Pink    */
static char termcol9[] = "#bd93f9";	 /* Purple    */
static char termcol10[] = "#ff5555"; /* Red    */
static char termcol11[] = "#f1fa8c"; /* Yellow    */
static const char *colors[SchemeLast][2] = {
	/*     fg         bg       */
	[SchemeNorm] = {termcol3, termcol0},
	[SchemeSel] = {termcol9, termcol0},
	[SchemeSelHighlight] = {termcol9, termcol2},
	[SchemeNormHighlight] = {termcol3, termcol0},
	[SchemeOut] = {"#000000", "#00ffff"},
	[SchemeOutHighlight] = {termcol3, "#00ffff"},
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
