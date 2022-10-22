/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx       = 1;   /* border pixel of windows */
static const unsigned int snap           = 32;  /* snap pixel */
static const unsigned int gappih         = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 10;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 10;  /* vert outer gap between windows and screen edge */
static const int smartgaps               = 1;   /* 1 means no outer gap when there is only one window */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray             = 1;   /* 0 means no systray */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const char *fonts[]               = { "JetBrains Mono:size=15" };
static const char dmenufont[]			 = "JetBrains Mono:size=15";
static const char col_gray1[]            = "#222222";
static const char col_gray2[]            = "#444444";
static const char col_gray3[]            = "#bbbbbb";
static const char col_gray4[]            = "#ffffff";
static const char col_cyan[]			 = "#37474F";
static const char col_border[]           = "#FF75BC";
static const unsigned int baralpha       = 0x9E;
static const unsigned int borderalpha    = OPAQUE;
static const char *colors[][3]           = {
	/*               fg         bg         border      */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2   },
	[SchemeSel]  = { col_gray4, col_cyan,  col_border  },
	[SchemeHid]  = { col_cyan,  col_gray1, col_border  },
};
static const unsigned int alphas[][3]    = {
	/*               fg      bg        border      */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = {"", "", "", "", "", "", "", ""};

static const Rule rules[] = {
	/* xproP(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class					instance    title       tags mask     isfloating   monitor */
		{"GoldenDict",			NULL,		NULL,		0,			1,			-1},
		{"Wine",				NULL,		NULL,		0,			1,			-1},
		{"wemeetapp",			NULL,		NULL,		0,			1,			-1},
		{"zoom",				NULL,		NULL,		0,			1,			-1},
		{"Microsoft-edge-dev",	NULL,		NULL,		1,			0,			-1},
		{"firefox", 			NULL,       NULL,       1,       	0,          -1},
		{"Google-chrome",		NULL,		NULL,		1,			0,			-1},
		{"Chromium",			NULL,		NULL,		1,			0,			-1},
		{"wpp",  				NULL,       NULL,       1<<1,       0,          -1},
		{"wps",                 NULL,       NULL,       1<<1,       0,          -1},
		{"pdf",                 NULL,       NULL,       1<<1,       0,          -1},
		{"et",                 	NULL,      	NULL,       1<<1,       0,          -1},
		{"Foxit Reader",        NULL,       NULL,       1<<1,       0,          -1},
		{"Code", 				NULL,       NULL,       1<<2,       0,          -1},
		{"VSCodium",			NULL,		NULL,		1<<2,		0,			-1},
		{"jetbrains-studio",  	NULL,       NULL,       1<<2,       0,          -1},
		{"jetbrains-idea",  	NULL,       NULL,       1<<2,       0,          -1},
		{"Pcmanfm",             NULL,       NULL,       1<<3,       0,          -1},
		{"Gimp-2.10",           NULL,       NULL,       1<<4,       0,          -1},
		{"vlc",                 NULL,       NULL,       1<<5,       0,          -1},
		{"bomi",                NULL,       NULL,       1<<5,       0,          -1},
		{"smplayer",            NULL,       NULL,       1<<5,       0,          -1},
		{"mpv",                 NULL,       NULL,       1<<5,       0,          -1},
		{"yesplaymusic",        NULL,       NULL,       1<<6,       0,          -1},
		{"VirtualBox Manager",  NULL,       NULL,       1<<7,       1,          -1},
};

/* layout(s) */
static const float mfact      = 0.5;  /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const int resizehints  = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol    arrange function */
	{ "[T]",    tile             },    /* first entry is default */
	{ "[F]",	NULL             },    /* no layout function means floating behavior */
	{ "[M]",	monocle          },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* custom commands*/
static const char *browsercmd[]  = { "google-chrome-stable", NULL };
static const char *upvolcmd[]       = { "/home/volta/suckless/scripts/vol-up.sh",      NULL };
static const char *filemanager[] = {"pcmanfm", NULL};
static const char *lockcmd[] = {"slock", NULL};
static const char *downvolcmd[]     = { "/home/volta/suckless/scripts/vol-down.sh",    NULL };
static const char *mutevolcmd[]     = { "/home/volta/suckless/scripts/vol-toggle.sh",  NULL };
static const char *upbacklightcmd[]	= { "/home/volta/suckless/scripts/backlight-up.sh", NULL };
static const char *downbacklightcmd[]	= { "/home/volta/suckless/scripts/backlight-down.sh", NULL };
static const char *screenshotcmd[]  = { "/home/volta/suckless/scripts/screenshot.sh",  NULL };
static const char *wpchangecmd[]	= {"/home/volta/suckless/scripts/wp-change.sh", NULL};
/* commands */
static char dmenumon[2] = "0";
static const char *menucmd[]	=	{"dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL};
static const char *termcmd[]	= {"st", NULL};
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[]	= {"st", "-t", scratchpadname, "-g", "60x15", NULL};


static Key keys[] = {
	/* modifier                     key            function        argument              */
	{ MODKEY,                       XK_c,          spawn,          {.v = browsercmd }    },
	{ MODKEY,						XK_e,		   spawn,		   {.v = filemanager }   },
	{ MODKEY|ShiftMask,				XK_l,		   spawn,		   {.v = lockcmd }   },
	{ MODKEY,             			XK_F3,         spawn,          {.v = upvolcmd }      },
	{ MODKEY,             			XK_F2,         spawn,          {.v = downvolcmd }    },
	{ MODKEY,			            XK_F1,         spawn,          {.v = mutevolcmd }    },
	{ MODKEY,             			XK_F12,        spawn,          {.v = upbacklightcmd }   },
	{ MODKEY,             			XK_F11,        spawn,          {.v = downbacklightcmd } },
	{ MODKEY,						XK_w,		   spawn,		   {.v = wpchangecmd }	},
	{ MODKEY,                       XK_d,          spawn,          {.v = menucmd }      },
	{ MODKEY,                       XK_Return,     spawn,          {.v = termcmd }       },
	{ NULL,             			XK_Print,      spawn,          {.v = screenshotcmd } },
	{ MODKEY,                       XK_apostrophe, togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,                       XK_b,          togglebar,      {0}                   },
	{ MODKEY|ShiftMask,             XK_Right,      rotatestack,    {.i = +1 }            },
	{ MODKEY|ShiftMask,             XK_Left,       rotatestack,    {.i = -1 }            },
	{ MODKEY,                       XK_Left,       focusstack,     {.i = +1 }            },
	{ MODKEY,                       XK_Right,      focusstack,     {.i = -1 }            },
	{ MODKEY,                       XK_o,          incnmaster,     {.i = +1 }            },
	{ MODKEY,                       XK_p,          incnmaster,     {.i = -1 }            },
	{ MODKEY,                       XK_h,          setmfact,       {.f = -0.05}          },
	{ MODKEY,                       XK_l,          setmfact,       {.f = +0.05}          },
	{ MODKEY|Mod1Mask,              XK_h,          incrgaps,       {.i = +1 }            },
	{ MODKEY|Mod1Mask,              XK_l,          incrgaps,       {.i = -1 }            },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_h,          incrogaps,      {.i = +1 }            },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_l,          incrogaps,      {.i = -1 }            },
	{ MODKEY|Mod1Mask|ControlMask,  XK_h,          incrigaps,      {.i = +1 }            },
	{ MODKEY|Mod1Mask|ControlMask,  XK_l,          incrigaps,      {.i = -1 }            },
	{ MODKEY|Mod1Mask,              XK_0,          togglegaps,     {0}                   },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,          defaultgaps,    {0}                   },
	{ MODKEY,                       XK_u,          incrihgaps,     {.i = +1 }            },
	{ MODKEY,                       XK_i,          incrihgaps,     {.i = -1 }            },
	{ MODKEY|ControlMask,           XK_u,          incrivgaps,     {.i = +1 }            },
	{ MODKEY|ControlMask,           XK_i,          incrivgaps,     {.i = -1 }            },
	{ MODKEY|Mod1Mask,              XK_u,          incrohgaps,     {.i = +1 }            },
	{ MODKEY|Mod1Mask,              XK_i,          incrohgaps,     {.i = -1 }            },
	{ MODKEY|ShiftMask,             XK_u,          incrovgaps,     {.i = +1 }            },
	{ MODKEY|ShiftMask,             XK_i,          incrovgaps,     {.i = -1 }            },
	{ MODKEY|ShiftMask,             XK_Return,     zoom,           {0}                   },
	{ MODKEY,                       XK_Tab,        view,           {0}                   },
	{ MODKEY|ShiftMask,	            XK_q,          killclient,     {0}                   },
	{ MODKEY|ShiftMask,             XK_t,          setlayout,      {.v = &layouts[0]}    },
	{ MODKEY|ShiftMask,             XK_f,          setlayout,      {.v = &layouts[1]}    },
	{ MODKEY|ShiftMask,             XK_m,          setlayout,      {.v = &layouts[2]}    },
	{ MODKEY,                       XK_f,          fullscreen,     {0}                   },
	{ MODKEY,                       XK_space,      setlayout,      {0}                   },
	{ MODKEY|ShiftMask,             XK_space,      togglefloating, {0}                   },
	{ MODKEY,                       XK_0,          view,           {.ui = ~0 }           },
	{ MODKEY|ShiftMask,             XK_0,          tag,            {.ui = ~0 }           },
	{ MODKEY,                       XK_comma,      focusmon,       {.i = -1 }            },
	{ MODKEY,                       XK_period,     focusmon,       {.i = +1 }            },
	{ MODKEY|ShiftMask,             XK_comma,      tagmon,         {.i = -1 }            },
	{ MODKEY|ShiftMask,             XK_period,     tagmon,         {.i = +1 }            },
	TAGKEYS(                        XK_1,          0                                     )
	TAGKEYS(                        XK_2,          1                                     )
	TAGKEYS(                        XK_3,          2                                     )
	TAGKEYS(                        XK_4,          3                                     )
	TAGKEYS(                        XK_5,          4                                     )
	TAGKEYS(                        XK_6,          5                                     )
	TAGKEYS(                        XK_7,          6                                     )
	TAGKEYS(                        XK_8,          7                                     )
	TAGKEYS(                        XK_9,          8                                     )
	{ MODKEY|ControlMask|ShiftMask, XK_c,          quit,           {0}                   },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument           */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0}                },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[1]} },
	{ ClkWinTitle,          0,              Button1,        togglewin,      {0}                },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0}                },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd }    },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0}                },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0}                },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0}                },
	{ ClkTagBar,            0,              Button1,        view,           {0}                },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0}                },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0}                },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0}                },
};

