// +------------------------------------------------------------------+
// |             ____ _               _        __  __ _  __           |
// |            / ___| |__   ___  ___| | __   |  \/  | |/ /           |
// |           | |   | '_ \ / _ \/ __| |/ /   | |\/| | ' /            |
// |           | |___| | | |  __/ (__|   <    | |  | | . \            |
// |            \____|_| |_|\___|\___|_|\_\___|_|  |_|_|\_\           |
// |                                                                  |
// | Copyright Mathias Kettner 2014             mk@mathias-kettner.de |
// +------------------------------------------------------------------+
//
// This file is part of Check_MK.
// Copyright by Mathias Kettner and Mathias Kettner GmbH.  All rights reserved.
//
// Check_MK is free software;  you can redistribute it and/or modify it
// under the  terms of the  GNU General Public License  as published by
// the Free Software Foundation in version 2.
//
// Check_MK is  distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY;  without even the implied warranty of
// MERCHANTABILITY  or  FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have  received  a copy of the  GNU  General Public
// License along with Check_MK.  If  not, email to mk@mathias-kettner.de
// or write to the postal address provided at www.mathias-kettner.de

#ifndef PerfdataAggregator_h
#define PerfdataAggregator_h

#include <map>
#include <string>
#include "Aggregator.h"

class StringColumn;

struct perf_aggr {
    double _aggr;
    double _count;
    double _sumq;
};

class PerfdataAggregator : public Aggregator
{
    StringColumn *_column;
    typedef std::map<std::string, perf_aggr> _aggr_t;
    _aggr_t _aggr;

public:
    PerfdataAggregator(StringColumn *c, int o) : Aggregator(o), _column(c) {}
    void consume(void *data, Query *);
    void output(Query *);

private:
    void consumeVariable(const char *varname, double value);
};

#endif // PerfdataAggregator_h

