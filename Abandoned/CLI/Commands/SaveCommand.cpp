#include "SaveCommand.hpp"
#include "Exception.hpp"
#include "../Serializing/SaveItemToFileSerializer.hpp"

#include <fstream>
#include <iostream>

/// TODO: I don't like this, forgot w, h, x, y version... hdfbigbhfdhv
void SaveCommand::execute(CommandType parsedCmd, std::shared_ptr<Document> doc) {  
    MapPair<Key, Value> pairs = parsedCmd.get<1>();
    std::string fileWPath = pairs["-file"].get<std::string>();
    std::ofstream fileToSave(fileWPath, ios::out | ios::binary);
    if (!fileToSave.is_open()) {
        throw Exception("File didn't open: " + fileWPath);
    }
    else if (fileToSave.is_open()) {
        auto slides = doc->getSlides();
        Idx idx = 0;
        for (const auto& slide : slides) {
            for (const auto& item : slide->getSlide()) {
                SaveItemToFileSerializer sitf(fileWPath, fileToSave, idx, item);
                sitf.execute();
            }
            ++idx;
        }
        fileToSave.close();
    }
}

      /*for (const auto& slide : doc->getSlides()) {
            auto count = 0;
            fileToSave << "slide" << " " << count << std::endl;
            for (const auto& item : slide->getSlide()) {
                fileToSave << item->getID() << " " << item->getType() << " ";
                auto pos = item->getPosition();
                NumberType l = pos.first.first;
                NumberType t = pos.first.second;
                NumberType r = pos.second.first;
                NumberType b = pos.second.second;
                fileToSave << " " << l << " " << t << " " << r << " " << b << " ";

                auto attrs = item->getAttributes();
                for (const auto& attr : attrs) {
                fileToSave << attrs.getKey(attr);
                if (std::is_same_v<decltype(attr), int>) {
                    try {
                        fileToSave << attr.get<int>() << " ";
                    } catch (const std::bad_variant_access&) {
                        std::cerr << "bad variant access in save attr int" << std::endl;
                    }
                }
                else if (std::is_same_v<decltype(attr), double>) {
                    try {
                        fileToSave << attr.get<double>() << " ";
                    } catch (const std::bad_variant_access&) {
                        std::cerr << "bad variant access in save attr double" << std::endl;
                    }
                }
                else if (std::is_same_v<decltype(attr), std::string>) {
                    try {
                        fileToSave << attr.get<std::string>() << " ";
                    } catch (const std::bad_variant_access&) {
                        std::cerr << "bad variant access in save attr string" << std::endl;
                    }
                }
            }
            }
            fileToSave << std::endl;
            ++count;
        }
    }*/
