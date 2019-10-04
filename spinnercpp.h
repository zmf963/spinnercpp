#ifndef __SPINNERCPP__
#define __SPINNERCPP__

#include <string>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>
#include <iostream>

namespace spinnercpp {
	using namespace std;

	vector<vector<string>> CharSets = {
		{"←", "↖", "↑", "↗", "→", "↘", "↓", "↙"},
		{"▁", "▃", "▄", "▅", "▆", "▇", "█", "▇", "▆", "▅", "▄", "▃", "▁"},
		{"▖", "▘", "▝", "▗"},
		{"┤", "┘", "┴", "└", "├", "┌", "┬", "┐"},
		{"◢", "◣", "◤", "◥"},
		{"◰", "◳", "◲", "◱"},
		{"◴", "◷", "◶", "◵"},
		{"◐", "◓", "◑", "◒"},
		{".", "o", "O", "@", "*"},
		{"|", "/", "-", "\\"},
		{"◡◡", "⊙⊙", "◠◠"},
		{"⣾", "⣽", "⣻", "⢿", "⡿", "⣟", "⣯", "⣷"},
		{">))'>", " >))'>", "  >))'>", "   >))'>", "    >))'>", "   <'((<", "  <'((<", " <'((<"},
		{"⠁", "⠂", "⠄", "⡀", "⢀", "⠠", "⠐", "⠈"},
		{"⠋", "⠙", "⠹", "⠸", "⠼", "⠴", "⠦", "⠧", "⠇", "⠏"},
		{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"},
		{"▉", "▊", "▋", "▌", "▍", "▎", "▏", "▎", "▍", "▌", "▋", "▊", "▉"},
		{"■", "□", "▪", "▫"},
		{"←", "↑", "→", "↓"},
		{"╫", "╪"},
		{"⇐", "⇖", "⇑", "⇗", "⇒", "⇘", "⇓", "⇙"},
		{"⠁", "⠁", "⠉", "⠙", "⠚", "⠒", "⠂", "⠂", "⠒", "⠲", "⠴", "⠤", "⠄", "⠄", "⠤", "⠠", "⠠", "⠤", "⠦", "⠖", "⠒", "⠐", "⠐", "⠒", "⠓", "⠋", "⠉", "⠈", "⠈"},
		{"⠈", "⠉", "⠋", "⠓", "⠒", "⠐", "⠐", "⠒", "⠖", "⠦", "⠤", "⠠", "⠠", "⠤", "⠦", "⠖", "⠒", "⠐", "⠐", "⠒", "⠓", "⠋", "⠉", "⠈"},
		{"⠁", "⠉", "⠙", "⠚", "⠒", "⠂", "⠂", "⠒", "⠲", "⠴", "⠤", "⠄", "⠄", "⠤", "⠴", "⠲", "⠒", "⠂", "⠂", "⠒", "⠚", "⠙", "⠉", "⠁"},
		{"⠋", "⠙", "⠚", "⠒", "⠂", "⠂", "⠒", "⠲", "⠴", "⠦", "⠖", "⠒", "⠐", "⠐", "⠒", "⠓", "⠋"},
		{"ｦ", "ｧ", "ｨ", "ｩ", "ｪ", "ｫ", "ｬ", "ｭ", "ｮ", "ｯ", "ｱ", "ｲ", "ｳ", "ｴ", "ｵ", "ｶ", "ｷ", "ｸ", "ｹ", "ｺ", "ｻ", "ｼ", "ｽ", "ｾ", "ｿ", "ﾀ", "ﾁ", "ﾂ", "ﾃ", "ﾄ", "ﾅ", "ﾆ", "ﾇ", "ﾈ", "ﾉ", "ﾊ", "ﾋ", "ﾌ", "ﾍ", "ﾎ", "ﾏ", "ﾐ", "ﾑ", "ﾒ", "ﾓ", "ﾔ", "ﾕ", "ﾖ", "ﾗ", "ﾘ", "ﾙ", "ﾚ", "ﾛ", "ﾜ", "ﾝ"},
		{".", "..", "..."},
		{"▁", "▂", "▃", "▄", "▅", "▆", "▇", "█", "▉", "▊", "▋", "▌", "▍", "▎", "▏", "▏", "▎", "▍", "▌", "▋", "▊", "▉", "█", "▇", "▆", "▅", "▄", "▃", "▂", "▁"},
		{".", "o", "O", "°", "O", "o", "."},
		{"+", "x"},
		{"v", "<", "^", ">"},
		{">>--->", " >>--->", "  >>--->", "   >>--->", "    >>--->", "    <---<<", "   <---<<", "  <---<<", " <---<<", "<---<<"},
		{"|", "||", "|||", "||||", "|||||", "|||||||", "||||||||", "|||||||", "||||||", "|||||", "||||", "|||", "||", "|"},
		{"[          ]", "[=         ]", "[==        ]", "[===       ]", "[====      ]", "[=====     ]", "[======    ]", "[=======   ]", "[========  ]", "[========= ]", "[==========]"},
		{"(*---------)", "(-*--------)", "(--*-------)", "(---*------)", "(----*-----)", "(-----*----)", "(------*---)", "(-------*--)", "(--------*-)", "(---------*)"},
		{"█▒▒▒▒▒▒▒▒▒", "███▒▒▒▒▒▒▒", "█████▒▒▒▒▒", "███████▒▒▒", "██████████"},
		{"[                    ]", "[=>                  ]", "[===>                ]", "[=====>              ]", "[======>             ]", "[========>           ]", "[==========>         ]", "[============>       ]", "[==============>     ]", "[================>   ]", "[==================> ]", "[===================>]"},
		{"🌍", "🌎", "🌏"},
		{"◜", "◝", "◞", "◟"},
		{"⬒", "⬔", "⬓", "⬕"},
		{"⬖", "⬘", "⬗", "⬙"},
		{"[>>>          >]", "[]>>>>        []", "[]  >>>>      []", "[]    >>>>    []", "[]      >>>>  []", "[]        >>>>[]", "[>>          >>]"},
		{"♠", "♣", "♥", "♦"},
		{"➞", "➟", "➠", "➡", "➠", "➟"},
		//{"  |  ", ` \   `, "_    ", ` \   `, "  |  ", "   / ", "    _", "   / "},
		//{"  . . . .", ".   . . .", ". .   . .", ". . .   .", ". . . .  ", ". . . . ."},
		//{" |     ", "  /    ", "   _   ", `    \  `, "     | ", `    \  `, "   _   ", "  /    "},
		//{"⎺", "⎻", "⎼", "⎽", "⎼", "⎻"},
		//{"▹▹▹▹▹", "▸▹▹▹▹", "▹▸▹▹▹", "▹▹▸▹▹", "▹▹▹▸▹", "▹▹▹▹▸"},
		//{"[    ]", "[   =]", "[  ==]", "[ ===]", "[====]", "[=== ]", "[==  ]", "[=   ]"},
		//{"( ●    )", "(  ●   )", "(   ●  )", "(    ● )", "(     ●)", "(    ● )", "(   ●  )", "(  ●   )", "( ●    )"},
		//{"✶", "✸", "✹", "✺", "✹", "✷"},
		//{"▐|\\____________▌", "▐_|\\___________▌", "▐__|\\__________▌", "▐___|\\_________▌", "▐____|\\________▌", "▐_____|\\_______▌", "▐______|\\______▌", "▐_______|\\_____▌", "▐________|\\____▌", "▐_________|\\___▌", "▐__________|\\__▌", "▐___________|\\_▌", "▐____________|\\▌", "▐____________/|▌", "▐___________/|_▌", "▐__________/|__▌", "▐_________/|___▌", "▐________/|____▌", "▐_______/|_____▌", "▐______/|______▌", "▐_____/|_______▌", "▐____/|________▌", "▐___/|_________▌", "▐__/|__________▌", "▐_/|___________▌", "▐/|____________▌"},
		//{"▐⠂       ▌", "▐⠈       ▌", "▐ ⠂      ▌", "▐ ⠠      ▌", "▐  ⡀     ▌", "▐  ⠠     ▌", "▐   ⠂    ▌", "▐   ⠈    ▌", "▐    ⠂   ▌", "▐    ⠠   ▌", "▐     ⡀  ▌", "▐     ⠠  ▌", "▐      ⠂ ▌", "▐      ⠈ ▌", "▐       ⠂▌", "▐       ⠠▌", "▐       ⡀▌", "▐      ⠠ ▌", "▐      ⠂ ▌", "▐     ⠈  ▌", "▐     ⠂  ▌", "▐    ⠠   ▌", "▐    ⡀   ▌", "▐   ⠠    ▌", "▐   ⠂    ▌", "▐  ⠈     ▌", "▐  ⠂     ▌", "▐ ⠠      ▌", "▐ ⡀      ▌", "▐⠠       ▌"},
		//{"¿", "?"},
		//{"⢹", "⢺", "⢼", "⣸", "⣇", "⡧", "⡗", "⡏"},
		//{"⢄", "⢂", "⢁", "⡁", "⡈", "⡐", "⡠"},
		//{".  ", ".. ", "...", " ..", "  .", "   "},
		//{".", "o", "O", "°", "O", "o", "."},
		//{"▓", "▒", "░"},
		//{"▌", "▀", "▐", "▄"},
		//{"⊶", "⊷"},
		//{"▪", "▫"},
		//{"□", "■"},
		//{"▮", "▯"},
		//{"-", "=", "≡"},
		//{"d", "q", "p", "b"},
		//{"∙∙∙", "●∙∙", "∙●∙", "∙∙●", "∙∙∙"},
		//{"🌑 ", "🌒 ", "🌓 ", "🌔 ", "🌕 ", "🌖 ", "🌗 ", "🌘 "},
		//{"☗", "☖"},
		//{"⧇", "⧆"},
		//{"◉", "◎"},
		//{"㊂", "㊀", "㊁"},
		//{"⦾", "⦿"},
		//{"ဝ", "၀"},
		{"▌", "▀", "▐▄"},
	};


	class spinner {
		public:
			spinner() : delay_(200),
			chars_(0),
			finalmsg_(""),
			prefix_(""),
			suffix_(""),
			active_(true) {				
			}

			~spinner() {
				stop();
			}

			void start() {
				thr_ = thread([&](){
						int c = 0;
						auto chars = CharSets[chars_];
						int l = CharSets[chars_].size();

						while (active_)  { 
						        cout << "\r" << chars[c++ % l]; 
							std::this_thread::sleep_for(delay_);
						}
				});
			}

			void stop() {
				active_ = false;
				std::this_thread::sleep_for(delay_);
			}

		private:
			chrono::duration<int,std::milli> delay_;
			string prefix_;
			string suffix_;
			int chars_;
			string finalmsg_;
			bool active_;
			mutex lock_;
			thread thr_;
	};
}

#endif

