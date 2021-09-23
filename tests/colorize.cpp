/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:48:06 by iwillens          #+#    #+#             */
/*   Updated: 2021/09/23 18:48:45 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colorize.hpp"

bool ft::Colorize::colorized { true } ;

ft::Colorize::Colorize(): ft::Colorize::Colorize("") {};

ft::Colorize::Colorize(Colorize const &c) { *this = c; }

ft::Colorize::Colorize(std::string s, int color, int attributes, int background)
: _text(s), _color(color), _background(background), _lightforeground(false), _lightbackground(false), _bold(false)
{
    if (attributes & CLR_LIGHTFG)
        this->lightForeground();
    if (attributes & CLR_LIGHTBG)
        this->lightBackground();
    attributes = attributes & 15;
    if (attributes == CLR_BOLD)
        this->Bold();
};

ft::Colorize::~Colorize() {};

ft::Colorize &ft::Colorize::operator=(Colorize const &c)
{
    this->_text = c._text;
    this->_color = c._color;
    this->_background = c._background;
    this->_lightforeground = c._lightforeground;
    this->_lightbackground = c._lightbackground;
    this->_bold = c._bold;
    return (*this);
}

void ft::Colorize::lightForeground(bool enabled) { this->_lightforeground = enabled; }
void ft::Colorize::lightBackground(bool enabled) { this->_lightbackground = enabled; }
void ft::Colorize::Bold(bool enabled) { this->_bold = enabled; }
void ft::Colorize::Black() { this->_color = CLR_BLACK; }
void ft::Colorize::Red() { this->_color = CLR_RED; }
void ft::Colorize::Green() { this->_color = CLR_GREEN; }
void ft::Colorize::Yellow() { this->_color = CLR_YELLOW; }
void ft::Colorize::Blue() { this->_color = CLR_BLUE; }
void ft::Colorize::Magenta() { this->_color = CLR_MAGENTA; }
void ft::Colorize::Cyan() { this->_color = CLR_CYAN; }
void ft::Colorize::White() { this->_color = CLR_WHITE; }
void ft::Colorize::bgBlack() { this->_background = CLR_BLACK; }
void ft::Colorize::bgRed() { this->_background = CLR_RED; }
void ft::Colorize::bgGreen() { this->_background = CLR_GREEN; }
void ft::Colorize::bgYellow() { this->_background = CLR_YELLOW; }
void ft::Colorize::bgBlue() { this->_background = CLR_BLUE; }
void ft::Colorize::bgMagenta() { this->_background = CLR_MAGENTA; }
void ft::Colorize::bgCyan() { this->_background = CLR_CYAN; }
void ft::Colorize::bgWhite() { this->_background = CLR_WHITE; }

void ft::Colorize::setText(std::string s) { this->_text = s; }

void ft::Colorize::print()
{
    std::string str("\033[");
    int attributes = 0;
    int color = this->_color;
    int background = this->_background;

    if (this->colorized)
    {
        if (color && this->_lightforeground)
            color += 60;
        if (background)
            background += 10;
        if (background && this->_lightbackground)
            background += 60;
        if (this->_bold)
            attributes = CLR_BOLD;
        str += std::to_string(attributes);
        str +=  ";" + std::to_string(color);
        if (background)
            str += ";" + std::to_string(background);
        str += "m";
        str += this->_text;
        str += "\033[0m";
        std::cout << str;
    }
    else
    {
        std::cout << this->_text << std::endl;
    }
}

