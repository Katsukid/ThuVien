[% INCLUDE 'blocking_errors.inc' %]
<div id="toolbar" class="btn-toolbar">
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown"><i class="fa fa-plus"></i> Tạo mới <span class="caret"></span></button>
 <ul class="dropdown-menu">
 <li><a href="/cgi-bin/koha/patroncards/edit-batch.pl?op=new">Card batch</a></li>
 <li><a href="/cgi-bin/koha/patroncards/image-manage.pl">Hình ảnh</a></li>
 <li><a href="/cgi-bin/koha/patroncards/edit-layout.pl?op=new">Layout</a></li>
 <li><a href="/cgi-bin/koha/patroncards/edit-template.pl?op=new">Card template</a></li>
 <li><a href="/cgi-bin/koha/patroncards/edit-profile.pl?op=new">Printer profile</a></li>
 </ul>
 </div>
 <div class="btn-group">
 <button class="btn btn-default dropdown-toggle" data-toggle="dropdown"><i class="fa fa-edit"></i> Manage <span class="caret"></span></button>
 <ul class="dropdown-menu">
 <li><a href="/cgi-bin/koha/patroncards/manage.pl?card_element=batch">Card batches</a></li>
 <li><a href="/cgi-bin/koha/patroncards/image-manage.pl">Ảnh bìa</a></li>
 <li><a href="/cgi-bin/koha/patroncards/manage.pl?card_element=layout">Layouts</a></li>
 <li><a href="/cgi-bin/koha/patroncards/manage.pl?card_element=template">Card templates</a></li>
 <li><a href="/cgi-bin/koha/patroncards/manage.pl?card_element=profile">Mẫu in</a></li>
 </ul>
 </div>
</div>
