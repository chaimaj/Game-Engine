/* 
 * File:   ResourceManager.cpp
 * Author: PC-Z510
 * 
 * Created on 4 mars 2015, 19:28
 */


#include <fstream>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>

#include "ResourceManager.h"
#include "Sprite.h"
#include "Frame.h"
#include "LogManager.h"

using namespace std;

int returnColor (string color);

ResourceManager::ResourceManager() {
}

int readLineInt(ifstream *p_file, const char *tag);
string readLineStr(ifstream *p_file, const char *tag);
Frame readFrame(ifstream *p_file, int width, int height);
void discardCR(string &str);


bool ResourceManager::instanceFlag = false;
ResourceManager* ResourceManager::single = NULL;

ResourceManager* ResourceManager::GetInstance() {
    {
        if (!instanceFlag) {
            single = new ResourceManager();
            instanceFlag = true;
            return single;
        } else {
            return single;
        }
    }
}

/// Get manager ready for resources.

int ResourceManager::startUp() {
    sprite_count = 0;
    Manager::startUp();
}

/// Shut down manager, freeing up any allocated Sprites.

void ResourceManager::shutDown() {
    for (int i = 0; i < sprite_count; i++) {
        delete p_sprite[i];
    }
    Manager::shutDown();
}

/// Load Sprite from file.
/// Assign indicated label to Sprite.
/// Return 0 if ok, else -1.

int ResourceManager::loadSprite(string filename, string label) {
    LogManager *log = LogManager::GetInstance();
    const char * c = filename.c_str();

    ifstream myfile(c);

    int frame;
    int width;
    int height;
    string color;
    Sprite *spr;
    string line;

    //Open File
    if (myfile.is_open()) {
        int i = 1;
        //repeat until end of file

        while ((myfile.good())&& (i <= 4)) {
            //read header
            switch (i) {
                case 1: // Note the colon, not a semicolon
                    getline(myfile, line);
                    discardCR(line);
                    frame = atoi(line.substr(strlen("frames") + 1).c_str());
                    //cout << "frames " << frame << "\n";
                    break;
                case 2: // Note the colon, not a semicolon
                    getline(myfile, line);
                    discardCR(line);
                    width = atoi(line.substr(strlen("width") + 1).c_str());
                    //cout << "width " << width << "\n";
                    break;
                case 3: // Note the colon, not a semicolon
                    getline(myfile, line);
                    discardCR(line);
                    height = atoi(line.substr(strlen("height") + 1).c_str());
                    //cout << "height " << height << "\n";
                    break;
                case 4: // Note the colon, not a semicolon
                    getline(myfile, line);
                    discardCR(line);
                    color = line.substr(strlen("color") + 1);
                    //cout << "color " << color << "\n";
                    break;
            }
            i++;
        }
        //create Sprite with number of frames
        spr = new Sprite(frame);
        spr->setWidth(width);
        spr->setHeight(height);
        spr->setColor(returnColor(color));
        bool eof = false;

        while ((myfile.good()) && (!eof)) {
            // Check if not end of line
            string frame_str = "";

            for (int j = 0; j <= height; j++) {
                getline(myfile, line);
                discardCR(line);
                if ((line.size() != width)&&(line != "end")&&(line != "eof")) {
                    //report to log
                    log->writeLog(" error line %d line size %d doesn't match width %d", i, line.size(), width);
                    Frame empty;
                    spr->addFrame(empty);

                } else if (line == "eof") {
                    eof = true;
                    break;
                } else if (line != "end") {
                    frame_str += line;
                }
                i++;
            }
            if (frame_str != "") {
                cout << frame_str << "\n";
                Frame frame(width, height, frame_str);
                spr->addFrame(frame);
            }
        }
        //        //close file when done
    } else {
        log->writeLog(" enable to open file ");
        return -1;
    }
    myfile.close();
    spr->setLabel(label);
    p_sprite[sprite_count] = spr;
    sprite_count++;

    return 0;
}

///helper functions for loading sprites

//Read single line 'tag number', return number

int readLineInt(ifstream *p_file, const char *tag) {
    int number = 0;
    if (p_file->is_open()) {
        if (p_file->good()) {
            string line;
            getline(*p_file, line);
            discardCR(line);
            if (!line.compare(0, strlen(tag), tag)) {
                return -1;
            }
            int number = atoi(line.substr(strlen(tag) + 1).c_str());
            number = 5;
        }
    }
    return number;

}

//Read single line 'tag string', return string

string readLineStr(ifstream *p_file, const char *tag) {
    string line;
    getline(*p_file, line);
    discardCR(line);
    if (!line.compare(0, strlen(tag), tag)) {
        return NULL;
    }
    string final = line.substr(strlen(tag) + 1);

    return final;

}

//Read frame until 'eof', return Frame

Frame readFrame(ifstream *p_file, int width, int height) {
    string line, frame_str;
    for (int i = 1; i <= height; i++) {
        getline(*p_file, line);
        discardCR(line);
        if (line.size() != width) {
            Frame empty;
            return empty;
        }
        frame_str += line;
    }

    getline(*p_file, line);
    if (line != "end") {
        Frame empty;
        return empty;
    }
    cout << "frame " << frame_str;
    Frame frame(width, height, frame_str);

    return frame;
}

//Remove '\r' from line (if there typical of windows)

void discardCR(string & str) {
    if ((str.size() > 0) && (str[str.size() - 1] == '\r')) {
        cout << "erase" << str[str.size() - 1];
        str.erase(str.size() - 1);
    }
}

/// Unload Sprite with indicated label.
/// Return 0 if ok, else -1.

int ResourceManager::unloadSprite(string label) {
    for (int i = 0; i < sprite_count; i++) {
        if (label == p_sprite[i]->getLabel()) {
            delete p_sprite[i];
            for (int j = i; j < sprite_count - 1; j++) {
                p_sprite[j] = p_sprite[j - 1];
            }
            sprite_count--;
            return 0;
        }

    }
    return -1;
}

/// Find Sprite with indicated label.
/// Return pointer to it if found, else NULL.

Sprite * ResourceManager::getSprite(string label) const {
    for (int i = 0; i < sprite_count; i++) {
        if (label == p_sprite[i]->getLabel()) {
            return p_sprite[i];
        }
    }
    return NULL;
}

int ResourceManager::getSpriteCount() const {
    return sprite_count;
}

bool ResourceManager::isValid(string event_type) const{
    
}

int returnColor (string color){
    if (color == "black")
            return 0;
    else if (color == "red")
            return 1;
    else if (color == "green")
            return 2;
    else if (color == "yellow")
            return 3;
    else if (color == "blue")
            return 4;
    else if (color == "magenta")
            return 5;
    else if (color == "cyan")
            return 6;
    
    return 7;
}



