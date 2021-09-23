/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:30:16 by iwillens          #+#    #+#             */
/*   Updated: 2021/09/23 18:44:46 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORIZE_HPP
# define COLORIZE_HPP

# include <string>
# include <iostream>

# define CLR_BLACK		30
# define CLR_RED		31
# define CLR_GREEN		32
# define CLR_YELLOW		33
# define CLR_BLUE		34
# define CLR_MAGENTA	35
# define CLR_CYAN		36
# define CLR_WHITE		37

/*
** attributes light and lightbg can be added using | bitwise operator.
** ex: CLR_BOLD | CLR_LIGHTBG | CLR_LIGHTFG
*/

# define CLR_DEFAULT		0
# define CLR_BOLD			1
# define CLR_DIM			2
# define CLR_ITALICS		3
# define CLR_UNDERLINED		4
# define CLR_BLINK			5
# define CLR_REVERSE		7
# define CLR_HIDDEN			8
# define CLR_LIGHTFG		16
# define CLR_LIGHTBG		32

namespace ft
{
	class Colorize
	{
		
		private:
			std::string 	_text;
			int				_color;
			int				_background;
			bool			_lightforeground;
			bool			_lightbackground;
			bool			_bold;

		public:
			Colorize();
			Colorize(Colorize const &c);
			Colorize(std::string s, int color = CLR_DEFAULT, int attributes = CLR_DEFAULT, int background = CLR_DEFAULT);
			virtual ~Colorize();
			Colorize &operator=(Colorize const &c);
			static bool		colorized;
			void setText(std::string s);
			void lightForeground(bool enabled = true);
			void lightBackground(bool enabled = true);
			void Bold(bool enabled = true);
			void Black();
			void Red();
			void Green();
			void Yellow();
			void Blue();
			void Magenta();
			void Cyan();
			void White();
			void bgBlack();
			void bgRed();
			void bgGreen();
			void bgYellow();
			void bgBlue();
			void bgMagenta();
			void bgCyan();
			void bgWhite();
			void print();
	};
}

#endif