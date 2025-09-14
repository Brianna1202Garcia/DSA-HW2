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
			E.clear();
			S.clear();
            ifstream fin;
			fin.open(filename);

			if(!fin.is_open()) return;
			string word;

			Entry e;
			e.pop = 0;

			int i = 0;
			while(fin >> word) {
				e.hashtag = word;
				E.push_back(e);
				if (i < 3) S.push_back(i++);
			}

			fin.close();
        }
  
		// Return the number of hashtags in the Trendtracker.
		//
		// Must run in O(1) time.
		int Trendtracker::size() {
			return E.size();
        }

		// Adds 1 to the total number times a hashtag has been tweeted.
		// If the hashtag does not exist in TrendTracker, does nothing.
		//
		// Must run in O(log(n)) time.
		void Trendtracker::tweeted(string ht) {
			int found = search(ht);
			if (found == -1) return;
 			
			E[found].pop++;

			// Update top trends
			//Get top items
			vector<string> T;
			top_three_trends(T);

			//Check if ht is here
			int i = 0;
			for (; i < S.size(); i ++) {
				if (E[S[i]].hashtag == ht) break;
			}

			switch (i) {
				
				case 2 : {
					if (E[S[2]].pop > E[S[1]].pop)
						swap(S[1], S[2]);
					if (E[S[1]].pop > E[S[0]].pop)
						swap(S[0], S[1]);
					break;
				}

				case 1: {
					if (E[S[1]].pop > E[S[0]].pop) 
						swap(S[0], S[1]);
				}
				default: break;
			} 

			for (int k = 0; k < S.size (); k++) {
				if (found != S[k] ? E[S[k]].pop < E[found].pop : false) {
					int index1 = found, index2 = found;
					switch(k) {
						case 0 :
						{

						}
						case 1 :
						{

						}
						case 2 :
						{

						}
					}
				}

				//Ternary operation
				// if (x > y) then (x) else (y)
				//x > y ? x : y
			}
			
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
			if (!S.size()) return;
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
			T.clear();
			if (!S.size()) return;
			
			for (int i = 0; i < S.size(); i++) {
				T.push_back(E[S[i]].hashtag);
			}
        } 

		// Optional helper method.
		// Returns the index of E containing an Entry with hashtag ht.
		// If no such hashtag is found, returns -1.
		//
		// Should run in O(log(n)).
		int Trendtracker::search(string ht){
			if (!E.size()) return -1;
			int start = 0, end = E.size() - 1, middle;

			//we loop while the start is less than the end
			 while (start <= end) {
				//get the middle
				middle = (start+end)/2;

				//compare with ht
				if (E[middle].hashtag == ht) {
					return middle;
				}
				//when the middle is smaller than the hashtag
				else if (E[middle].hashtag < ht){ 
					start = middle + 1;
				}
				else end = middle - 1;
			 } 
			 return -1;
		}
