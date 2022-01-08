<p align="center">
	<img width="130px;" src="https://raw.githubusercontent.com/iwillenshofer/resources/main/images/42_logo_black.svg" align="center" alt="42" />&nbsp;&nbsp;&nbsp;
	<img width="130px" src="https://raw.githubusercontent.com/iwillenshofer/resources/main/achievements/ft_containers.png" align="center" alt="ft_containers" />
	<h1 align="center">ft_containers</h1>
</p>
<p align="center">
	<img src="https://img.shields.io/badge/Success-125/100_✓-gray.svg?colorA=61c265&colorB=4CAF50&style=for-the-badge">
	<img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black">
	<img src="https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=apple&logoColor=white">
</p>

<p align="center">
	<b><i>Development repository for the 42cursus ft_containers project @ 42 São Paulo</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/iwillenshofer/ft_containers?color=blueviolet" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/iwillenshofer/ft_containers?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/commit-activity/t/iwillenshofer/ft_containers?color=brightgreen" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/iwillenshofer/ft_containers?color=brightgreen" />
</p>
<br>

> _The multiple available containers in C++ all have a very different usage. To make sure you understand them all, let's re-implement them!_



<br>

<p align="center">
	<table>
		<tr>
			<td><b>Est. Time</b></td>
			<td><b>Skills</b></td>
			<td><b>Difficulty</b></td>
		</tr>
		<tr>
			<td valign="top">140 hours</td>
			<td valign="top">
<img src="https://img.shields.io/badge/Object-oriented programming-555">
<img src="https://img.shields.io/badge/Rigor-555">
			</td>
			<td valign="top"> 10042 XP</td>
		</tr>
	</table>
</p>

<br>

### Usage
```bash
# create a main file with your favorite container. Example below:
$ clang++ main.cpp
$ ./a.out
```

### main.cpp example
```cpp
#include <iostream>
#include "vector.hpp"

int main(void)
{
	ft::vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << "Number: " << *it << std::endl;
	v.clear();
	return (0);
}

```
### Tests
```bash
$ ./ft_containers --help

./ft_containers && ./std_containers --help

 _         _  _  _
<_> _ _ _ <_>| || | ___ ._ _  ___
| || | | || || || |/ ._>| ' |<_-<
|_||__/_/ |_||_||_|\___.|_|_|/__/

Syntax:
  $ ./ft_containers [compare] [container [large_number] ]
  $ ./std_containers [compare] [container [large_number] ]


Commands:
        compare
                Displays a coloured output comparing time of execution and results between STL containers and ft:: containers.
                If this option is enabled, ./ft_containers and ./std_containers behaviour is exactly the same.
                Otherwise, ./ft_containers will print the output of ft:: containers and ./std_containers will display the output of the original STL containers.

        container
                select one of these:
                vector
                map
                stack
                set     (bonus)
                all     will output all of the above. Same as if left blank.

        large_number     the number of tests to be done for map and set. Defaults to 1000, limit is 100000.


Examples:
  $ ./ft_containers compare
  $ ./ft_containers compare vector
  $ ./ft_containers compare all 10000
  $ diff <(./ft_containers) <(./std_containers)
  $ diff <(./ft_containers map) <(./std_containers map)
  $ diff <(./ft_containers map 10000) <(./std_containers map 10000)
```
