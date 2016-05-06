#include "golf_course.hpp"

using namespace std;


GolfCourse::GolfCourse()  {
  for (size_t i = 0; i < 18; i++) {
      hole_lock.push_back(new boost::mutex());
      party_at_hole.push_back(-1);
      hole_signalling.push_back(new boost::condition_variable());
      last_lock = new boost::mutex();
  }
}


double GolfCourse::average_turnaround_time() {
  boost::xtime sum;
  sum.sec = 0;
  sum.nsec = 0;

  vector<boost::xtime>::iterator it;

  for (auto individual_result : turnaround_times) {
    sum.sec += individual_result.sec;
    sum.nsec += individual_result.nsec;
  }

  return (sum.sec + sum.nsec / 1e9) / turnaround_times.size();
}
