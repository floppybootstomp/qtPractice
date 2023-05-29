CONFIG += debug

HEADERS += "headers/*" \
           "gameObjects/headers/*" \
           "backgrounds/headers/*"

SOURCES += "main/*" \
           "sources/*" \
           "gameObjects/sources/*" \
           "backgrounds/sources/*"

RESOURCES += "res.qrc"

OBJECTS_DIR = "objects"

MOC_DIR = "moc"

QT += gui opengl widgets

TARGET = memes

QMAKE_CXXFLAGS += -Os
