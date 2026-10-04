#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>
#include <iostream>
#include <algorithm>

int main()
{
    // OBRÁZEK 
    std::string PATH = "/mnt/c/Users/honza/Desktop/Lipidy.jpg";
    // ========================================

    // Načtení Obrázku
    cv::Mat img = cv::imread(PATH);
    if (img.empty()) {
        std::cout << "Image not found!" << std::endl;
        return -1;
    }

    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    // Detekce buněk
    cv::SimpleBlobDetector::Params params;

    params.filterByColor = false;

    params.filterByArea = true;
    params.minArea = 1500;
    params.maxArea = 30000;

    params.filterByCircularity = true;
    params.minCircularity = 0.5f;

    params.filterByConvexity = false;
    params.filterByInertia = false;

    params.minThreshold = 5;
    params.maxThreshold = 200;
    params.thresholdStep = 10;

    // Tvorba detektoru
    cv::Ptr<cv::SimpleBlobDetector> detector = cv::SimpleBlobDetector::create(params);

    // Výpočet počtu buněk
    std::vector<cv::KeyPoint> keypoints;
    detector->detect(gray, keypoints);

    // Seřazení podle velikosti
    std::sort(keypoints.begin(), keypoints.end(),
              [](const cv::KeyPoint &a, const cv::KeyPoint &b) {
                  return a.size < b.size;
              });

    cv::Mat highlight = img.clone();

    // Vykreslení výsledků
    int label = 1;
    for (const auto &kp : keypoints) {
        int x = static_cast<int>(kp.pt.x);
        int y = static_cast<int>(kp.pt.y);
        int r = static_cast<int>(kp.size / 2);

        // červený kruh obkreslující buňky
        cv::circle(highlight, cv::Point(x, y), r, cv::Scalar(0, 0, 255), 2);

        // Zelený zvýrazňující obdelník
        cv::rectangle(highlight,
                      cv::Point(x - r, y - r),
                      cv::Point(x + r, y + r),
                      cv::Scalar(0, 255, 0),
                      2);

    
        cv::putText(highlight,
                    std::to_string(label),
                    cv::Point(x - r, y - r - 5),
                    cv::FONT_HERSHEY_SIMPLEX,
                    0.8,
                    cv::Scalar(0, 255, 0),
                    2);

        label++;
    }

    // Uložení a zobrazení výsledků
    cv::imwrite("/mnt/c/Users/honza/Desktop/highlighted_cells_sorted_cpp.png", highlight);

    std::cout << "Detected cells: " << keypoints.size() << std::endl;

    cv::imshow("Detekce bunek", highlight);
    cv::waitKey(0);

    return 0;
}
