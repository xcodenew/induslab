#!/lsi/soft/CFR/bin/python
import sys
readfile = sys.argv[1]
writefile = readfile + ".out"

open_read_file = open(readfile,'r')
open_write_file = open(writefile,'w')
num_cases = int(open_read_file.readline())
for case in range(num_cases):
    previous_max_engine = ""
    engine_list = []
    query_list = []
    num_engines = int(open_read_file.readline())
    for engine in range(num_engines):
        engine_list.append(open_read_file.readline().strip('\n'))
    num_query = int(open_read_file.readline())
    if num_query == 0:
        open_write_file.write("Case #")
        open_write_file.write(str(case+1))
        open_write_file.write(": ")
        open_write_file.write('0')
        open_write_file.write('\n')
        continue
    for query in range(num_query):
        query_list.append(open_read_file.readline().strip('\n'))
    print "initial engine list = ", engine_list
    print "initial query list = ", query_list
    switch = 0
    while query_list != []: 
        max_occ = 0
        first_occ = 0
        num_query = len(query_list)
	temp_engine_list = engine_list[:]
        if previous_max_engine in engine_list:
            print "engine list = ", engine_list
            print "previous max engine = ", previous_max_engine
            temp_engine_list.remove(previous_max_engine)
            print "temp engine list", temp_engine_list
        print "temp engine list", temp_engine_list
        for engine in temp_engine_list:
            try:
                first_occ = query_list.index(engine)
            except:
                first_occ = num_query
            print "engine = ", engine, " first occ = ", first_occ
            if first_occ > max_occ:
                max_occ = first_occ
                max_engine = engine
        if len(temp_engine_list) == 1:
            max_engine = temp_engine_list[0]
        if max_occ == num_query:
            query_list = []
            break
        print "max_occ", max_occ
        print "max_engine", max_engine
        print "new query list ",  query_list[max_occ:]
        while query_list[max_occ] == max_engine:
            max_occ = max_occ + 1
            if max_occ == num_query:
                break 
        if max_occ == num_query:
            switch = switch + 1
            query_list = []
        else:
            query_list = query_list[max_occ:]
            switch = switch + 1
        print "max_occ = ", max_occ
        print "query list = ", query_list
        previous_max_engine = max_engine
    print "switch = ", switch
    print "case # ", case
    open_write_file.write("Case #")
    open_write_file.write(str(case+1))
    open_write_file.write(": ")
    open_write_file.write(str(switch))
    open_write_file.write('\n')

