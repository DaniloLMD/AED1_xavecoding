all: _remove _compile

_compile: MergeSort\
		  CountingSort

_remove:
	rm -rf MergeSort
	rm -rf CountingSort

merge:
	./MergeSort

count:
	./CountingSort

%: %.c
	gcc $< -o $@ 
