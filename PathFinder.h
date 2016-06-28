/*
 * SpatialMapping.h
 *
 *  Created on: Jun 25, 2016
 *      Author: ericwadkins
 */

#ifndef SPATIALMAPPING_H_
#define SPATIALMAPPING_H_

#include <set>
#include <map>
#include <limits>

#include "Simulation.h"
#include "Ray.h"

class PathFinder : public Simulation {
public:
	cv::Mat1f observedMap;
	std::vector<cv::Point> path;

	PathFinder(const char* imagePath);
	~PathFinder() {}
	void onStart();
	void onData(std::vector<std::pair<Ray, double> > rayMap);
	void onDisplayBackground(cv::Mat display, double scale);
	void onDisplayForeground(cv::Mat display, double scale);
	void keyListener(int key);
	std::vector<cv::Point> findPath(cv::Mat1f map, cv::Point start, cv::Point goal);
private:
	static const bool allowLocationAccess;
	static const bool allowMapAccess;
	static const bool allowImageAccess;

	cv::Point start;
	cv::Point goal;
};

#endif /* SPATIALMAPPING_H_ */