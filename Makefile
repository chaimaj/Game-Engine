#
# Makefile for development of game using Dragonfly
#
# 'make' to build executable
# 'make depend' to generate new dependency list
# 'make clean' to remove all constructed files
## Variables of interest:
#   GAMESRC is the source code files for the game being developed
#   GAME is the game main() source
#   DEBUG can be set to -DDEBUG to enable various debug flags
#

CC= g++
PLATFORM= -DCYGWIN
LDFLAGS= -lncurses -lrt -lm
#INCPATH= include
#LIBRARY=libdragonfly.a
ENGSRC= \
    EventView.cpp\
    ViewObject.cpp\
    Box.cpp\
    ResourceManager.cpp\
    Frame.cpp\
    Sprite.cpp\
    Star.cpp\
    ObjectCollider.cpp\
    EventCollision.cpp\
    EventOut.cpp\
    EventKeyboard.cpp\
    EventMouse.cpp\
    InputManager.cpp\
    GraphicsManager.cpp\
    ObjectTest.cpp\
    EventStep.cpp\
    Event.cpp\
    ObjectListIterator.cpp\
    ObjectList.cpp\
    Object.cpp\
    Position.cpp\
    Clock.cpp\
    utility.cpp\
    Manager.cpp \
    WorldManager.cpp \
    GameManager.cpp \
    LogManager.cpp \
	

GAME= game.cpp
EXECUTABLE= game
OBJECTS = $(ENGSRC:.cpp=.o)
	
#$(LIBRARY): $(OBJECTS) Makefile
#	ar rcs $(LIBRARY) $(OBJECTS)

all: $(EXECUTABLE) Makefile
 
$(EXECUTABLE):	$(OBJECTS)  $(GAME) $(ENGSRC) 
	$(CC) $(GAME) $(OBJECTS) -o $@ $(LDFLAGS)
 
.cpp.o:	
	$(CC) -c $(DEBUG)   $(PLATFORM) $< -o $@
#debug:	$(CC)	$(CXXFLAGS)	$(OBJECTS)	-o	$@	$(LDFLAGS)
 
clean:
	rm -rf	$(OBJECTS)	$(EXECUTABLE)	core dragonfly.log Makefile.bak *~
 
depend:	
	makedepend *.cpp 2> /dev/null

# DO NOT DELETE

Box.o: Box.h Position.h
Clock.o: /usr/include/time.h /usr/include/_ansi.h /usr/include/newlib.h
Clock.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Clock.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Clock.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Clock.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Clock.o: /usr/include/machine/time.h /usr/include/sys/types.h
Clock.o: /usr/include/machine/types.h Clock.h
Event.o: Event.h
EventCollision.o: EventCollision.h Event.h Object.h Position.h Sprite.h
EventCollision.o: Frame.h Box.h
EventKeyboard.o: EventKeyboard.h Event.h
EventMouse.o: EventMouse.h Event.h
EventOut.o: EventOut.h Event.h
EventStep.o: EventStep.h Event.h
EventView.o: EventView.h Event.h
Frame.o: Frame.h
game.o: /usr/include/stdio.h /usr/include/_ansi.h /usr/include/newlib.h
game.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
game.o: /usr/include/sys/features.h /usr/include/sys/cdefs.h
game.o: /usr/include/machine/_default_types.h /usr/include/sys/reent.h
game.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
game.o: /usr/include/sys/lock.h /usr/include/sys/types.h
game.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
game.o: /usr/include/time.h /usr/include/machine/time.h /usr/include/stdlib.h
game.o: /usr/include/machine/stdlib.h /usr/include/alloca.h LogManager.h
game.o: Manager.h Event.h Object.h Position.h Sprite.h Frame.h Box.h
game.o: ObjectList.h ObjectListIterator.h Clock.h GameManager.h
game.o: WorldManager.h GraphicsManager.h /usr/include/ncurses/curses.h
game.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
game.o: /usr/include/bits/wordsize.h /usr/include/unctrl.h
game.o: /usr/include/curses.h ObjectTest.h ObjectCollider.h Star.h
game.o: ResourceManager.h ViewObject.h
GameManager.o: /usr/include/time.h /usr/include/_ansi.h /usr/include/newlib.h
GameManager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
GameManager.o: /usr/include/sys/features.h /usr/include/sys/reent.h
GameManager.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
GameManager.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
GameManager.o: /usr/include/machine/time.h /usr/include/sys/types.h
GameManager.o: /usr/include/machine/types.h GameManager.h Manager.h Event.h
GameManager.o: Object.h Position.h Sprite.h Frame.h Box.h ObjectList.h
GameManager.o: ObjectListIterator.h LogManager.h /usr/include/stdio.h
GameManager.o: /usr/include/sys/cdefs.h /usr/include/sys/stdio.h Clock.h
GameManager.o: WorldManager.h EventStep.h GraphicsManager.h
GameManager.o: /usr/include/ncurses/curses.h /usr/include/ncurses_dll.h
GameManager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
GameManager.o: /usr/include/unctrl.h /usr/include/curses.h InputManager.h
GraphicsManager.o: GraphicsManager.h /usr/include/ncurses/curses.h
GraphicsManager.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
GraphicsManager.o: /usr/include/bits/wordsize.h /usr/include/stdio.h
GraphicsManager.o: /usr/include/_ansi.h /usr/include/newlib.h
GraphicsManager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
GraphicsManager.o: /usr/include/sys/features.h /usr/include/sys/cdefs.h
GraphicsManager.o: /usr/include/machine/_default_types.h
GraphicsManager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
GraphicsManager.o: /usr/include/machine/_types.h /usr/include/sys/lock.h
GraphicsManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
GraphicsManager.o: /usr/include/sys/stdio.h /usr/include/unctrl.h
GraphicsManager.o: /usr/include/curses.h Manager.h Event.h Object.h
GraphicsManager.o: Position.h Sprite.h Frame.h Box.h ObjectList.h
GraphicsManager.o: ObjectListIterator.h utility.h
InputManager.o: InputManager.h Manager.h Event.h Object.h Position.h Sprite.h
InputManager.o: Frame.h Box.h ObjectList.h ObjectListIterator.h
InputManager.o: GraphicsManager.h /usr/include/ncurses/curses.h
InputManager.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
InputManager.o: /usr/include/bits/wordsize.h /usr/include/stdio.h
InputManager.o: /usr/include/_ansi.h /usr/include/newlib.h
InputManager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
InputManager.o: /usr/include/sys/features.h /usr/include/sys/cdefs.h
InputManager.o: /usr/include/machine/_default_types.h
InputManager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
InputManager.o: /usr/include/machine/_types.h /usr/include/sys/lock.h
InputManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
InputManager.o: /usr/include/sys/stdio.h /usr/include/unctrl.h
InputManager.o: /usr/include/curses.h EventMouse.h EventKeyboard.h
InputManager.o: LogManager.h
LogManager.o: /usr/include/stdio.h /usr/include/_ansi.h /usr/include/newlib.h
LogManager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
LogManager.o: /usr/include/sys/features.h /usr/include/sys/cdefs.h
LogManager.o: /usr/include/machine/_default_types.h /usr/include/sys/reent.h
LogManager.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
LogManager.o: /usr/include/sys/lock.h /usr/include/sys/types.h
LogManager.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
LogManager.o: /usr/include/time.h /usr/include/machine/time.h LogManager.h
LogManager.o: Manager.h Event.h Object.h Position.h Sprite.h Frame.h Box.h
LogManager.o: ObjectList.h ObjectListIterator.h utility.h
Manager.o: Manager.h Event.h Object.h Position.h Sprite.h Frame.h Box.h
Manager.o: ObjectList.h ObjectListIterator.h WorldManager.h LogManager.h
Manager.o: /usr/include/stdio.h /usr/include/_ansi.h /usr/include/newlib.h
Manager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Manager.o: /usr/include/sys/features.h /usr/include/sys/cdefs.h
Manager.o: /usr/include/machine/_default_types.h /usr/include/sys/reent.h
Manager.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Manager.o: /usr/include/sys/lock.h /usr/include/sys/types.h
Manager.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
Object.o: Object.h Position.h Event.h Sprite.h Frame.h Box.h WorldManager.h
Object.o: Manager.h ObjectList.h ObjectListIterator.h LogManager.h
Object.o: /usr/include/stdio.h /usr/include/_ansi.h /usr/include/newlib.h
Object.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Object.o: /usr/include/sys/features.h /usr/include/sys/cdefs.h
Object.o: /usr/include/machine/_default_types.h /usr/include/sys/reent.h
Object.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Object.o: /usr/include/sys/lock.h /usr/include/sys/types.h
Object.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
Object.o: GraphicsManager.h /usr/include/ncurses/curses.h
Object.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
Object.o: /usr/include/bits/wordsize.h /usr/include/unctrl.h
Object.o: /usr/include/curses.h GameManager.h /usr/include/time.h
Object.o: /usr/include/machine/time.h EventKeyboard.h EventMouse.h
Object.o: InputManager.h EventStep.h /usr/include/math.h
ObjectCollider.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
ObjectCollider.o: /usr/include/_ansi.h /usr/include/newlib.h
ObjectCollider.o: /usr/include/sys/config.h /usr/include/sys/features.h
ObjectCollider.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
ObjectCollider.o: /usr/include/machine/_types.h
ObjectCollider.o: /usr/include/machine/_default_types.h
ObjectCollider.o: /usr/include/sys/lock.h /usr/include/machine/stdlib.h
ObjectCollider.o: /usr/include/alloca.h LogManager.h /usr/include/stdio.h
ObjectCollider.o: /usr/include/sys/cdefs.h /usr/include/sys/types.h
ObjectCollider.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
ObjectCollider.o: Manager.h Event.h Object.h Position.h Sprite.h Frame.h
ObjectCollider.o: Box.h ObjectList.h ObjectListIterator.h WorldManager.h
ObjectCollider.o: EventStep.h GraphicsManager.h /usr/include/ncurses/curses.h
ObjectCollider.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
ObjectCollider.o: /usr/include/bits/wordsize.h /usr/include/unctrl.h
ObjectCollider.o: /usr/include/curses.h EventKeyboard.h ObjectCollider.h
ObjectCollider.o: EventOut.h
ObjectList.o: ObjectList.h Object.h Position.h Event.h Sprite.h Frame.h Box.h
ObjectList.o: ObjectListIterator.h /usr/include/stdio.h /usr/include/_ansi.h
ObjectList.o: /usr/include/newlib.h /usr/include/sys/config.h
ObjectList.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
ObjectList.o: /usr/include/sys/cdefs.h /usr/include/machine/_default_types.h
ObjectList.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
ObjectList.o: /usr/include/machine/_types.h /usr/include/sys/lock.h
ObjectList.o: /usr/include/sys/types.h /usr/include/machine/types.h
ObjectList.o: /usr/include/sys/stdio.h /usr/include/stdlib.h
ObjectList.o: /usr/include/machine/stdlib.h /usr/include/alloca.h
ObjectList.o: /usr/include/string.h /usr/include/sys/string.h
ObjectListIterator.o: ObjectListIterator.h ObjectList.h Object.h Position.h
ObjectListIterator.o: Event.h Sprite.h Frame.h Box.h
ObjectTest.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
ObjectTest.o: /usr/include/_ansi.h /usr/include/newlib.h
ObjectTest.o: /usr/include/sys/config.h /usr/include/sys/features.h
ObjectTest.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
ObjectTest.o: /usr/include/machine/_types.h
ObjectTest.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
ObjectTest.o: /usr/include/machine/stdlib.h /usr/include/alloca.h
ObjectTest.o: ObjectTest.h Object.h Position.h Event.h Sprite.h Frame.h Box.h
ObjectTest.o: LogManager.h /usr/include/stdio.h /usr/include/sys/cdefs.h
ObjectTest.o: /usr/include/sys/types.h /usr/include/machine/types.h
ObjectTest.o: /usr/include/sys/stdio.h Manager.h ObjectList.h
ObjectTest.o: ObjectListIterator.h WorldManager.h EventStep.h
ObjectTest.o: GraphicsManager.h /usr/include/ncurses/curses.h
ObjectTest.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
ObjectTest.o: /usr/include/bits/wordsize.h /usr/include/unctrl.h
ObjectTest.o: /usr/include/curses.h EventKeyboard.h GameManager.h
ObjectTest.o: /usr/include/time.h /usr/include/machine/time.h EventView.h
Position.o: Position.h
ResourceManager.o: /usr/include/stdio.h /usr/include/_ansi.h
ResourceManager.o: /usr/include/newlib.h /usr/include/sys/config.h
ResourceManager.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
ResourceManager.o: /usr/include/sys/cdefs.h
ResourceManager.o: /usr/include/machine/_default_types.h
ResourceManager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
ResourceManager.o: /usr/include/machine/_types.h /usr/include/sys/lock.h
ResourceManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
ResourceManager.o: /usr/include/sys/stdio.h ResourceManager.h Manager.h
ResourceManager.o: Event.h Object.h Position.h Sprite.h Frame.h Box.h
ResourceManager.o: ObjectList.h ObjectListIterator.h LogManager.h
Sprite.o: Sprite.h Frame.h GraphicsManager.h /usr/include/ncurses/curses.h
Sprite.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
Sprite.o: /usr/include/bits/wordsize.h /usr/include/stdio.h
Sprite.o: /usr/include/_ansi.h /usr/include/newlib.h
Sprite.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Sprite.o: /usr/include/sys/features.h /usr/include/sys/cdefs.h
Sprite.o: /usr/include/machine/_default_types.h /usr/include/sys/reent.h
Sprite.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Sprite.o: /usr/include/sys/lock.h /usr/include/sys/types.h
Sprite.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
Sprite.o: /usr/include/unctrl.h /usr/include/curses.h Manager.h Event.h
Sprite.o: Object.h Position.h Box.h ObjectList.h ObjectListIterator.h
Star.o: Star.h Object.h Position.h Event.h Sprite.h Frame.h Box.h
Star.o: /usr/include/stdlib.h /usr/include/machine/ieeefp.h
Star.o: /usr/include/_ansi.h /usr/include/newlib.h /usr/include/sys/config.h
Star.o: /usr/include/sys/features.h /usr/include/sys/reent.h
Star.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Star.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Star.o: /usr/include/machine/stdlib.h /usr/include/alloca.h LogManager.h
Star.o: /usr/include/stdio.h /usr/include/sys/cdefs.h
Star.o: /usr/include/sys/types.h /usr/include/machine/types.h
Star.o: /usr/include/sys/stdio.h Manager.h ObjectList.h ObjectListIterator.h
Star.o: WorldManager.h EventStep.h GraphicsManager.h
Star.o: /usr/include/ncurses/curses.h /usr/include/ncurses_dll.h
Star.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
Star.o: /usr/include/unctrl.h /usr/include/curses.h EventKeyboard.h
Star.o: EventOut.h
utility.o: /usr/include/stdio.h /usr/include/_ansi.h /usr/include/newlib.h
utility.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
utility.o: /usr/include/sys/features.h /usr/include/sys/cdefs.h
utility.o: /usr/include/machine/_default_types.h /usr/include/sys/reent.h
utility.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
utility.o: /usr/include/sys/lock.h /usr/include/sys/types.h
utility.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
utility.o: /usr/include/time.h /usr/include/machine/time.h
utility.o: /usr/include/string.h /usr/include/sys/string.h utility.h
utility.o: Position.h Box.h Object.h Event.h Sprite.h Frame.h WorldManager.h
utility.o: Manager.h ObjectList.h ObjectListIterator.h LogManager.h
ViewObject.o: ViewObject.h Event.h Object.h Position.h Sprite.h Frame.h Box.h
ViewObject.o: WorldManager.h Manager.h ObjectList.h ObjectListIterator.h
ViewObject.o: GraphicsManager.h /usr/include/ncurses/curses.h
ViewObject.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
ViewObject.o: /usr/include/bits/wordsize.h /usr/include/stdio.h
ViewObject.o: /usr/include/_ansi.h /usr/include/newlib.h
ViewObject.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
ViewObject.o: /usr/include/sys/features.h /usr/include/sys/cdefs.h
ViewObject.o: /usr/include/machine/_default_types.h /usr/include/sys/reent.h
ViewObject.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
ViewObject.o: /usr/include/sys/lock.h /usr/include/sys/types.h
ViewObject.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
ViewObject.o: /usr/include/unctrl.h /usr/include/curses.h EventView.h
ViewObject.o: utility.h LogManager.h
WorldManager.o: WorldManager.h Manager.h Event.h Object.h Position.h Sprite.h
WorldManager.o: Frame.h Box.h ObjectList.h ObjectListIterator.h utility.h
WorldManager.o: EventCollision.h GraphicsManager.h
WorldManager.o: /usr/include/ncurses/curses.h /usr/include/ncurses_dll.h
WorldManager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
WorldManager.o: /usr/include/stdio.h /usr/include/_ansi.h
WorldManager.o: /usr/include/newlib.h /usr/include/sys/config.h
WorldManager.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
WorldManager.o: /usr/include/sys/cdefs.h
WorldManager.o: /usr/include/machine/_default_types.h
WorldManager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
WorldManager.o: /usr/include/machine/_types.h /usr/include/sys/lock.h
WorldManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
WorldManager.o: /usr/include/sys/stdio.h /usr/include/unctrl.h
WorldManager.o: /usr/include/curses.h EventOut.h LogManager.h ViewObject.h
