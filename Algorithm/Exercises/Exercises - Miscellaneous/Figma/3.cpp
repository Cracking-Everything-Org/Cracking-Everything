#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct Layer {
  string id;
  unordered_map<string, string> properties;
};

unordered_map<string, vector<Layer>> versions;
vector<string> layerTracker;

struct Document {
  Document(vector<Layer> layers) {
    versions = unordered_map<string, vector<Layer>>();

    for (int layer = 0; layer < layers.size(); layer++) {
      Layer currentLayer = layers[layer];
      if (versions.find(currentLayer.id) == versions.end()) {
        versions[currentLayer.id] = vector<Layer>();
      }
      versions[currentLayer.id].push_back(currentLayer);
    }

    layerTracker = vector<string>();
  }

  Layer& layerById(const string& id) {
      int size = versions[id].size();
      return versions[id][size - 1];
  }

  void apply(const string& id, const string& property, const string& value) {
    if (versions.find(id) == versions.end()) {
      return ;
    }
    int size = versions[id].size();
    Layer newLayer = versions[id][size - 1];
    newLayer.properties[property] = value;

    versions[id].push_back(newLayer);
    layerTracker.push_back(id);
  }

  void undo() {

    if (layerTracker.size() == 0) {
      return ;
    }

    cout << "layer tracker size: " << layerTracker.size() << endl;

    int lastLayerPosition = layerTracker.size() - 1;
    string lastLayerId = layerTracker[lastLayerPosition];

    cout << "layer ID: " << lastLayerId << endl;

    //layerTracker[lastLayerPosition].pop_back();
    versions[lastLayerId].pop_back();

    layerTracker.pop_back();
  }
};

void assertEqual(const string& actual, const string& expected) {
  if (actual == expected) {
    cout << "Assertion passed: actual & expected match: '" << actual << "'." << endl;
  } else {
    cout << "Assertion failed: expected '" << expected << "', got '" << actual << "'." << endl;
  }
}

void testUndo() {
  cout << "Testing undo" << endl;
  cout << "------------" << endl;

  Document document({
    {"a", {{"color", "red"}}},
  });

  document.apply("a", "color", "green");
  document.apply("a", "color", "blue");

  document.undo();
  assertEqual(document.layerById("a").properties["color"], "green");

  document.apply("a", "color", "purple");
  assertEqual(document.layerById("a").properties["color"], "purple");

  document.undo();
  assertEqual(document.layerById("a").properties["color"], "green");

  document.undo();
  assertEqual(document.layerById("a").properties["color"], "red");

  cout << endl;
}

int main() {
  testUndo();
}
