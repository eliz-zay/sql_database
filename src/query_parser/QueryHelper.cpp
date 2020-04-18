#pragma once

#include <string>
#include <vector>
#include <stack>

#include "../shared/StringHelper.cpp"
#include "QueryException.h"

using namespace std;

namespace QueryHelper {
    /*
     * Searches for key word (WHERE, IN, LIKE, ...) among query tokens
     * @param queryTokens - vector of query tokens
     * @param keyWord - key word to search
     * @returns index of found key word or -1 if not found
     */
    int searchKeyWordInVector(vector<string> queryTokens, string keyWord) {
        for (int i = 0; i < queryTokens.size(); i++) {
            if (StringHelper::getUpperString(queryTokens[i]) == StringHelper::getUpperString(keyWord)) {
                return i;
            }
        }

        return -1;
    }

    /*
     * Determines if the given token is nested in clause(between braces)
     * @param queryTokens - vector of query tokens
     * @param tokenIndex - index of token in vector
     * @return true if the token is nested, false if not
     */
    bool isTokenNested(vector<string> queryTokens, int tokenIndex) {
        stack<string> closures;

        for (int i = 0; i <= tokenIndex; i++) {
            if (queryTokens[i] == "(") {
                closures.push("(");
            } else if (queryTokens[i] == ")" && closures.empty()) {
                throw QueryException("Wrong braces placement");
            } else if (queryTokens[i] == ")" && !closures.empty()) {
                closures.pop();
            }
        }

        return !closures.empty();
    }

    /*
     * Parses query string into token vector
     * @param query - query string
     * @returns vector of tokens
     */
    vector<string> queryToTokenVector(string query) {
        StringHelper::replace(query, "\\s*[,]\\s*", ",");
        StringHelper::replace(query, "\\s*;\\s*", " ;");
        StringHelper::replace(query, "\\s*=\\s*", " = ");
        StringHelper::replace(query, "\\s*[(]\\s*", " ( ");
        StringHelper::replace(query, "\\s*[)]\\s*", " ) ");
        StringHelper::replace(query, "\\s*\\s\\s*", " ");

        vector<string> queryTokens = StringHelper::splitToVector(query, ' ');

        return queryTokens;
    }
}
