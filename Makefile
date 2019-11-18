CC=gcc
SOURCES=src/*.c
TARGET_DIR=target
TARGET=$(TARGET_DIR)/hello


hellomake: $(SOURCES)
	rm -rf $(TARGET_DIR)
	mkdir $(TARGET_DIR)
	$(CC) -o $(TARGET) $(SOURCES)
