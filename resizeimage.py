from PIL import Image
source_path = "opac/htdocs/opac-tmpl/bootstrap/images/logo-cdktqs1_base_old.jpg"
dest_path = "opac/htdocs/opac-tmpl/bootstrap/images/logo-cdktqs1.png"
image = Image.open(source_path)
image.thumbnail((80,80), Image.ANTIALIAS)
image.save(dest_path, "JPEG",quality=100)