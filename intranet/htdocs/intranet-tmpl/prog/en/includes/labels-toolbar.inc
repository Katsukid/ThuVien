[% INCLUDE 'blocking_errors.inc' %]
<div id="toolbar" class="btn-toolbar">
    <div class="btn-group">
        <button class="btn btn-default dropdown-toggle" data-toggle="dropdown"><i class="fa fa-plus"></i> New <span class="caret"></span></button>
        <ul class="dropdown-menu">
            <li><a href="/cgi-bin/koha/labels/label-edit-batch.pl?op=new">Lô nhãn</a></li>
            <li><a href="/cgi-bin/koha/labels/label-edit-layout.pl?op=new">Cách trình bày</a></li>
            <li><a href="/cgi-bin/koha/labels/label-edit-template.pl?op=new">Hình thức nhãn gáy</a></li>
            <li><a href="/cgi-bin/koha/labels/label-edit-profile.pl?op=new">Mẫu in</a></li>
            <li><a href="/cgi-bin/koha/labels/label-edit-range.pl">Phạm vi mã vạch</a></li>
        </ul>
    </div>
    <div class="btn-group">
        <button class="btn btn-default dropdown-toggle" data-toggle="dropdown"><i class="fa fa-edit"></i> Quản lý <span class="caret"></span></button>
        <ul class="dropdown-menu">
            <li><a href="/cgi-bin/koha/labels/label-manage.pl?label_element=batch">Lô nhãn</a></li>
            <li><a href="/cgi-bin/koha/labels/label-manage.pl?label_element=layout">Cách trình bày</a></li>
            <li><a href="/cgi-bin/koha/labels/label-manage.pl?label_element=template">Hình thức nhãn gáy</a></li>
            <li><a href="/cgi-bin/koha/labels/label-manage.pl?label_element=profile">Mẫu in</a></li>
        </ul>
    </div>
</div>
