#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int s, t;
    cin >> s >> t;
    vector<string> logic(s);

    vector<int> trues,falses,terms;
    for(int i = 1; i <= s; i++) {
        cin >> logic[i];
        if(logic[i] == "true") trues.push_back(i);
        else if(logic[i] == "false") falses.push_back(i);
        else if(logic[i] == "or") terms.push_back(i);
    }

    string answer = "";
    for(long i = 0; i < t; i++) {
        int l, r;
        string wantResult = "";
        cin >> l >> r >> wantResult;

        int sTerm = lower_bound(terms.begin(), terms.end(), l) - terms.begin();
        int eTerm = lower_bound(terms.begin(), terms.end(), r) - terms.begin();
        bool startTerm = (l == terms[sTerm]);
        bool endTerm = (r == terms[eTerm]);


        bool canContinue = true;
        if(!startTerm) {
            int totFalses = 0;
            if(falses.size() > 0) {
                totFalses = lower_bound(falses.begin(), falses.end(), l) - falses.begin();
                if(sTerm > 0) {
                    totFalses -= lower_bound(falses.begin(), falses.end(), terms[sTerm - 1]) - falses.begin();
                }
            }

            if(totFalses > 0) canContinue = false;
        }

        if(canContinue && !endTerm) {
            int totFalses = 0;
            if(falses.size() > 0) {
                totFalses = falses.size() - (lower_bound(falses.begin(), falses.end(), r) - falses.begin());
                if(eTerm > 0) {
                    totFalses -= falses.size() - (lower_bound(falses.begin(), falses.end(), terms[eTerm]) - falses.begin());
                }
            }

            if(totFalses > 0) canContinue = false;
        }
            
        if(sTerm > 0) sTerm--;
        if(eTerm > 0) eTerm--;
        int indexS = lower_bound(trues.begin(), trues.end(), terms[sTerm]) - trues.begin();
        int indexE = trues.size() - (lower_bound(trues.begin(), trues.end(), terms[eTerm]) - trues.begin());


        if(!canContinue) {
            if((indexS + indexE) > 0 && wantResult == "true") answer += "Y";
            else if((indexS + indexE) < 0 && wantResult == "true") answer += "N";
            else if((indexS + indexE) > 0 && wantResult == "false") answer += "N";
            else if((indexS + indexE) < 0 && wantResult == "false") answer += "Y";
        } else {
            
        }
    }
}