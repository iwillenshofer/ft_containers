# ft_containers Tests

## How this test works.
The tests behaviour depends on the result of a static variable `ft::Tester::kind`.

This variable is set by a MACRO defined on compile or according to the number of arguments (argc).

./ft_containers is compiled with `ft::Tester::kind = KIND_FT`
./std_containers is compiled with `ft::Tester::kind = KIND_STD`
Both binaries have `ft::Tester::kind` overriden to `KIND_COMPARE` if any argument is passed. ie: `./ft_containers 1`.

Some tester class functions will behave differently according to this kind:
`tester.printClock()` will do nothing unless `kind == KIND_COMPARE`.
`ft::Tester::Return()` will print the output of the return (it's argument) only if `kind != KIND_COMPARE`.



## Creating a Test.

### Main test function.
> The main function to call a test must have 4 parts:
> 1. The title. `tester.printName("Default Constructor");
> 2. The comparison functions `tester.compare`, which will call the templated
> tester function for ft:: as first argument and, as second argument,
> for std:: or bool (in case the
> tested function does not exist on std:: or is c++11.);
> 3. The same functions called in compare, but for ft:: only.
> 4. The same functions called in compare, but for std:: only.
> * Parts three and four should not be added if function does not exist on std:: in c++98.

#### Example:

```
void test_vector_default_constructor(ft::Tester &tester)
{
	//1. The title.
	tester.printName("Default Constructor");

	//2. Comparison functions. Will only be executed if ft::tester::kind = KIND_COMPARE.
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			default_constructor1< ft::vector<int> >(),
			default_constructor1< std::vector<int> >()
		);
		tester.compare(
			default_constructor1< ft::vector<float> >(),
			default_constructor1< std::vector<float> >()
		);
		tester.compare(
			default_constructor1< ft::vector<bool> >(),
			default_constructor1< std::vector<bool> >()
		);
	}

	//3. ft:: tests.
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		default_constructor1< ft::vector<int> >();
		default_constructor1< ft::vector<float> >();
		default_constructor1< ft::vector<bool> >();
		tester.printClock("[ft ]"); // Will only be printed if kind = KIND_COMPARE
	}

	//4. std:: tests.
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		default_constructor1< std::vector<int> >();
		default_constructor1< std::vector<float> >();
		default_constructor1< std::vector<bool> >();
		tester.printClock("[std]");
	}
	std::cout << std::endl;
}
```

### Individual test function.
> This function must be a template, and will perform the tests for both std:: and ft:: namespaces.

#### Example:

```
template <typename T>
std::string default_constructor1()
{
	T v;
	std::string s;

	s += "Capacity: " + ft::to_string(v.capacity()) + "\n";
	s += "Size: " + ft::to_string(v.size()) + "\n";
	s += "Content: \n";

	for (typename T::iterator it = v.begin(); it != v.end(); it++)
	{
		s += ft::to_string(*it) + "|";
	}
	return (ft::Tester::Return(s)); //returns s, but prints also print's to std::cout if kind != KIND_COMPARE.
}
```
