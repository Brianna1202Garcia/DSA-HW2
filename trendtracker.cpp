#include "trendtracker.h"

using namespace std;

// Creates a Trendtracker containing hashtags
		// found in the provided file.
		// The file is promised to have the following format:
		//
		// string1
		// string2
		// ...
		// stringN
		//
		// where string1 < string2 < ... < stringN
		//
		// Must run in O(n) time.
		Trendtracker::Trendtracker(string filename) {
            //i gotta open the file 
			ifstream file(filename);
			assert(file.is_open());

			string line;
			//read each line (loop)
			while(getline(file,line)) {
				//create an entry for each hashtag
				Entry e;
				e.hashtag = line;
				e.pop = 0;
				//store it 
				E.push_back(e);
			}

			//initialize top trends with the empty first 3
			for (int i = 0; i < 3 && i < E.size(); i++) {
				S.push_back(i);
			}
        }

		// Return the number of hashtags in the Trendtracker.
		//
		// Must run in O(1) time.
		int Trendtracker::size() {

        }

		// Adds 1 to the total number times a hashtag has been tweeted.
		// If the hashtag does not exist in TrendTracker, does nothing.
		//
		// Must run in O(log(n)) time.
		void Trendtracker::tweeted(string ht) {

        }

		// Returns the number of times a hashtag has been tweeted.
		// If the hashtag does not exist in Trendtracker, returns -1.
		//
		// Must run in O(log(n)) time.
		int Trendtracker::popularity(string name) {

        }

		// Returns a most-tweeted hashtag.
		// If the Trendtracker has no hashtags, returns "".
		//
		// Must run in O(1) time.
		string Trendtracker::top_trend() {
			return E[S[0]].hashtag;
        }

		// Fills the provided vector with the 3 most-tweeted hashtags,
		// in order from most-tweeted to least-tweeted.
		//
		// If there are fewer than 3 hashtags, then the vector is filled
		// with all hashtags (in most-tweeted to least-tweeted order).
		//
		// Must run in O(1) time.
		void Trendtracker::top_three_trends(vector<string> &T) {

        }
