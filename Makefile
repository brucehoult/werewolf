go: werewolf
	./werewolf

werewolf: werewolf.lid werewolf.dylan werewolf-exports.dylan
	d2c werewolf.lid

clean:
	-rm -f *.o *.s *.a *.c *.mak *~ werewolf
	-rm -rf .libs
