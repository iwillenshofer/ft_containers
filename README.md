# ft_containers

A 42 network project.


### How to run:

> make

> ./ft_containers --help

```
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

        large_number     the number of tests to be done for map and set. Defaults to 1.000, limit is 1.000.000.


Examples:
  $ ./ft_containers compare
  $ ./ft_containers compare vector
  $ ./ft_containers compare all 10000
  $ diff <(./ft_containers) <(./std_containers)
  $ diff <(./ft_containers map) <(./std_containers map)
  $ diff <(./ft_containers map 10000) <(./std_containers map 10000)
```