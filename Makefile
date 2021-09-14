.PHONY: clean All

All:
	@echo "----------Building project:[ PES_Assignment_2 - Debug ]----------"
	@cd "PES_Assignment_2" && "$(MAKE)" -f  "PES_Assignment_2.mk"
clean:
	@echo "----------Cleaning project:[ PES_Assignment_2 - Debug ]----------"
	@cd "PES_Assignment_2" && "$(MAKE)" -f  "PES_Assignment_2.mk" clean
