m := Cambios

save:
	git add .
	git commit -m "$(m)"
	git push

pull: 
	git pull

.PHONY: save pull 