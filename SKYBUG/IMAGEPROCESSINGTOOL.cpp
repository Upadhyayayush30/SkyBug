#include <QCoreApplication>
#include <QImage>
#include <QPixmap>
#include <QFileDialog>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void displayImage(const Mat& image) {
    // Convert OpenCV Mat to Qt QImage
    QImage img(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);

    // Display the image
    QPixmap pixmap = QPixmap::fromImage(img);
    pixmap.show();
}

void saveImage(const Mat& image, const string& filename) {
    imwrite(filename, image);
    cout << "Image saved successfully as " << filename << endl;
}

void applyGrayscale(Mat& image) {
    cvtColor(image, image, COLOR_BGR2GRAY);
}

void applyBlur(Mat& image) {
    GaussianBlur(image, image, Size(5, 5), 0);
}

void applySharpen(Mat& image) {
    Mat kernel = (Mat_<float>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    filter2D(image, image, image.depth(), kernel);
}

void adjustBrightnessContrast(Mat& image, double alpha, int beta) {
    image.convertTo(image, -1, alpha, beta);
}

void cropImage(Mat& image, int x, int y, int width, int height) {
    Rect roi(x, y, width, height);
    image = image(roi);
}

void resizeImage(Mat& image, int width, int height) {
    resize(image, image, Size(width, height));
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Load image
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Open Image", "", "Images (*.png *.jpg *.bmp)");
    if (fileName.isEmpty()) {
        cerr << "No image selected. Exiting..." << endl;
        return -1;
    }

    Mat originalImage = imread(fileName.toStdString());
    if (originalImage.empty()) {
        cerr << "Error loading image. Exiting..." << endl;
        return -1;
    }

    // Display original image
    displayImage(originalImage);

    // Image processing operations
    Mat processedImage = originalImage.clone();

    // Grayscale filter
    applyGrayscale(processedImage);
    displayImage(processedImage);

    // Blur filter
    applyBlur(processedImage);
    displayImage(processedImage);

    // Sharpen filter
    applySharpen(processedImage);
    displayImage(processedImage);

    // Adjust brightness and contrast
    adjustBrightnessContrast(processedImage, 1.5, 30);
    displayImage(processedImage);

    // Crop image
    cropImage(processedImage, 50, 50, 300, 300);
    displayImage(processedImage);

    // Resize image
    resizeImage(processedImage, 200, 200);
    displayImage(processedImage);

    // Save processed image
    saveImage(processedImage, "processed_image.jpg");

    return a.exec();
}
