# twoClassTSNE
Pre-Trained Imagenet based two class 2D T-SNE plot using Openfreameworks

![t-sne bad-clustered example]( https://github.com/bemoregt/twoClassTSNE/blob/master/ScrShot%2011.png "t-sne plot 1")

![t-sne good-clustered example]( https://github.com/bemoregt/twoClassTSNE/blob/master/ScrShot%2012.png "t-sne plot 2")

Two Classes images Clustering using pre-trained Imagenet model(VGG16).
- This program can used to check sanity of ground truth of directory-labeled data.
- Blue Box: class1 datas from good directory.
- Red Box: class2 datas from bad directory.

###How To
1. Enter your images to good & bad folder.
2. run Xcode program.
3. Control the GUI screen's Scale slider for entire Scale of t-sne plot.
3. Control the GUI screen's ImageSize slider for each images size.

### Dependency
- OpenFrameworks 0.10.1
- ofxCcv
- ofxGUI
- ofxTSNE
- XCode 10.12.x
- OSX Mojave

### Reference
original code from https://github.com/genekogan/ofxTSNE.git
