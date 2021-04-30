DOXY_FILE = SeatTemperature
doc:
	doxygen ./$(DOXY_FILE)

clean:
	rm -rf html*
