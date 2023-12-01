[% USE Koha %]
<!-- patrons-admin-search.inc -->
<div id="header_search" role="tablist">
 <div class="tab-content">
 <div id="patron_category_search" role="tabpanel" class="tab-pane active">
 <form action="[% script_name | html %]" method="post">
 <div class="form-title">
 <label class="control-label">Tìm kiểu bạn đọc</label>
 </div>

 <div class="form-content">
 <input class="head-searchbox form-control" type="text" name="description" value="[% searchfield | html %]" placeholder="Search by patron category name" />
 </div>

 <button type="submit"><i class="fa fa-arrow-right"></i></button>
 </form>
 </div>

 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 [% INCLUDE 'patron-search-box.inc' %]
 [% END %]

 [% IF ( CAN_user_catalogue ) %]
 [% INCLUDE 'catalogue-search-box.inc' %]
 [% END %]

 </div> <!-- /.tab-content -->
 <ul class="nav nav-tabs" role="tablist">
 <li role="presentation" class="active">
 <a aria-controls="patron_category_search" aria-expanded="true" class="keep_text" data-toggle="tab" href="#patron_category_search" role="tab" title="Tìm kiểu bạn đọc"><i class="fa fa-fw fa-id-card-o"></i> <span class="tab-title">Tìm kiểu bạn đọc</span></a>
 </li>
 [% IF ( CAN_user_circulate_circulate_remaining_permissions ) %]
 <li role="presentation">
 <a aria-controls="circ_search" class="keep_text" data-toggle="tab" href="#circ_search" role="tab" title="Ghi mượn"><i class="fa fa-upload"></i> <span class="tab-title">Ghi mượn</span></a>
 </li>
 [% END %]
 [% IF ( CAN_user_catalogue ) %]
 <li role="presentation">
 <a title="Search catalog" href="#catalog_search" aria-controls="catalog_search" role="tab" data-toggle="tab" class="keep_text"><i class="fa fa-fw fa-search"></i> <span class="tab-title">Tìm kiếm danh mục</span></a>
 </li>
 [% END %]
 </ul>
</div> <!-- /#header_search -->
<!-- /patrons-admin-search.inc -->
