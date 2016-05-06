#pragma once
#include <boost/thread/thread.hpp>
#include <boost/thread/barrier.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#include <boost/thread/xtime.hpp>
#include <vector>

using namespace std;


class GolfCourse {
// PUBLIC API METHODS
public:

  /**
   * Constructor.
   */
  GolfCourse();

  /**
   * Compute the average turnaround time over all the golfers that have
   * completed the course.
   */
  double average_turnaround_time();

// INSTANCE VARIABLES
public:

  // TODO: This is where you will define your barriers, condition variables, and
  // any other shared variables or synchronization primitives. The variables are
  // currently public to keep it simple.
  vector<boost::barrier*> party_barrier;
  vector<int> parties;
  vector<boost::mutex*> hole_lock;
  vector<int> party_at_hole;
  vector<boost::condition_variable*> hole_signalling;
  boost::mutex* last_lock;
  vector<int> last_ct;

  /**
   * Vector that gets populated with each golfer's turnaround time as they
   * finish the course.
   */
  std::vector<boost::xtime> turnaround_times;
};
