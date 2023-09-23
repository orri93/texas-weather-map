#ifndef _TEXAS_QUERIES_H_
#define _TEXAS_QUERIES_H_

#define QUERY_WORLD_CLOCK_API "http://worldclockapi.com/api/json/utc/now"
#define QUERY_WORLD_TIME_API  "http://worldtimeapi.org/api/timezone/utc"

const char* create_query(int location);

#endif /* _TEXAS_QUERIES_H_ */
