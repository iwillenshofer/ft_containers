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

namespace ft
{
	class Colorize
	{
		
		private:
			Colorize() {};
			std::string 	_text;
			int				_color;
			int				_background;
			bool			_lightforeground;
			bool			_lightbackground;
			bool			_bold;
			static bool		_colorized;

		public:
			Colorize(Colorize const &c) {};
			Colorize(std::string s);
			virtual ~Colorize();
			Colorize &operator=(Colorize const &c);
			

	};
}

#endif